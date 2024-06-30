/*
 * PROJECT:     ReactOS Setup Library
 * LICENSE:     GPL-2.0-or-later (https://spdx.org/licenses/GPL-2.0-or-later)
 * PURPOSE:     Device utility functions
 * COPYRIGHT:   Copyright 2024 Hermès Bélusca-Maïto <hermes.belusca-maito@reactos.org>
 */

#pragma once

/* FUNCTIONS *****************************************************************/

NTSTATUS
pOpenDeviceEx(
    _In_ PCWSTR DevicePath,
    _Out_ PHANDLE DeviceHandle,
    _In_ ACCESS_MASK DesiredAccess,
    _In_ ULONG ShareAccess);

NTSTATUS
pOpenDevice(
    _In_ PCWSTR DevicePath,
    _Out_ PHANDLE DeviceHandle);

/* PnP ENUMERATION SUPPORT HELPERS *******************************************/

typedef NTSTATUS
(NTAPI *PENUM_DEVICES_PROC)(
    _In_ const GUID* InterfaceClassGuid,
    _In_ PCWSTR DevicePath,
    _In_ HANDLE DeviceHandle,
    _In_opt_ PVOID Context);

NTSTATUS
pNtEnumDevicesPnP(
    _In_ const GUID* InterfaceClassGuid,
    _In_ PENUM_DEVICES_PROC Callback,
    _In_opt_ PVOID Context);

/* EOF */
