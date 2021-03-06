/** @file
  Copyright (c) 2014, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _UFS_PCI_HOST_CONTROLLER_PEI_H_
#define _UFS_PCI_HOST_CONTROLLER_PEI_H_

#include <pci.h>

#define UFS_HC_PEI_SIGNATURE    (SIGNATURE_32 ('U', 'F', 'S', 'P'))
#define MAX_UFS_HCS             8

typedef struct {
	UINTN                         Signature;
	UINTN                         TotalUfsHcs;
	UINTN                         UfsHcPciAddr[MAX_UFS_HCS];
} UFS_HC_PEI_PRIVATE_DATA;


/**
  Get the MMIO base address of UFS host controller.

  @param[in]  This               The protocol instance pointer.
  @param[in]  ControllerId       The ID of the UFS host controller.
  @param[out] MmioBar            Pointer to the UFS host controller MMIO base address.

  @retval EFI_SUCCESS            The operation succeeds.
  @retval EFI_INVALID_PARAMETER  The parameters are invalid.

**/
EFI_STATUS
EFIAPI
GetUfsHcMmioBar (
	IN     UFS_HC_PEI_PRIVATE_DATA       *Private,
	IN     UINT8                         ControllerId,
	OUT    UINTN                         *MmioBar
	);



/**
  The user code starts with this function.

  @param[out]  Private           A pointer to UFS_PEIM_HC_PRIVATE_DATA data structure.
  @param[in]   UfsHcPciBase      UFS Host Controller's PCI ConfigSpace Base address

  @retval EFI_SUCCESS            The driver is successfully initialized.
  @retval Others                 Can't initialize the driver.

**/
EFI_STATUS
EFIAPI
InitializeUfsHcPeim (
	OUT UFS_HC_PEI_PRIVATE_DATA    *Private,
	IN  pcidev_t                   pci_dev
	);

#endif
