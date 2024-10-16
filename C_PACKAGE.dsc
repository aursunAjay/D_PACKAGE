[Defines]
  PLATFORM_NAME                  = C_PACKAGE
  PLATFORM_GUID                  = 4690363f-06eb-462b-b287-68b210400f3d
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build\
  SUPPORTED_ARCHITECTURES        = X64|IA32
  BUILD_TARGETS                  = DEBUG|RELEASE|NOOPT
  SKUID_IDENTIFIER               = DEFAULT
  
[Components]
 
  # Chapter 6
  C_PACKAGE/Chapter6/Misc/MonoCount.inf
  C_PACKAGE/Chapter6/Misc/Reset.inf
  C_PACKAGE/Chapter6/Time/Time.inf
  C_PACKAGE/Chapter6/Variable/Variable.inf
  C_PACKAGE/Chapter6/VirtualMemory/ConvertPointer.inf
  C_PACKAGE/Chapter6/VirtualMemory/GetMemoryMap.inf

  # Chapter 7
  C_PACKAGE/Chapter7/C_PEIM/C_PEIM.inf
  C_PACKAGE/Chapter7/C_PEIM_2/C_PEIM_2.inf
  C_PACKAGE/Chapter7/C_DXE/C_DXE.inf
  C_PACKAGE/Chapter7/C_UEFI/C_UEFI.inf
  C_PACKAGE/Chapter7/DXE_Runtime/DXE_Runtime.inf
  C_PACKAGE/Chapter7/C_Application/C_Application.inf

  C_PACKAGE/Chapter7/C_ARCH_DXE/C_CPU/C_CPU.inf
  C_PACKAGE/Chapter7/C_ARCH_DXE/C_BDS/C_BDS.inf
  C_PACKAGE/Chapter7/C_ARCH_DXE/C_RTC/C_RTC.inf
  C_PACKAGE/Chapter7/C_ARCH_DXE/C_TIMER/C_TIMER.inf
  C_PACKAGE/Chapter7/C_ARCH_DXE/C_RESET/C_RESET.inf
  C_PACKAGE/Chapter7/C_ARCH_DXE/C_VAR/C_VAR.inf
  C_PACKAGE/Chapter7/C_ARCH_DXE/C_WATCHDOG/C_WATCHDOG.inf

  # Chapter 8
  C_PACKAGE/Chapter8/Metronome/Metronome.inf

  #chapter 9
  C_PACKAGE/Chapter9/C_PCI/C_PCI.inf
  C_PACKAGE/Chapter9/C_FS/C_FS.inf
  C_PACKAGE/Chapter9/C_DIO/C_DIO.inf
  C_PACKAGE/Chapter9/C_BIO/C_BIO.inf
  C_PACKAGE/Chapter9/C_UEFI_BIO/C_UEFI_BIO.inf
  C_PACKAGE/Chapter9/C_UEFI_DIO/C_UEFI_DIO.inf
 
[LibraryClasses]
  #
  # Entry point
  #
  PeiCoreEntryPoint|MdePkg/Library/PeiCoreEntryPoint/PeiCoreEntryPoint.inf
  PeimEntryPoint|MdePkg/Library/PeimEntryPoint/PeimEntryPoint.inf
  DxeCoreEntryPoint|MdePkg/Library/DxeCoreEntryPoint/DxeCoreEntryPoint.inf
  UefiDriverEntryPoint|MdePkg/Library/UefiDriverEntryPoint/UefiDriverEntryPoint.inf
  UefiApplicationEntryPoint|MdePkg/Library/UefiApplicationEntryPoint/UefiApplicationEntryPoint.inf
  #
  # Basic
  #
  BaseLib|MdePkg/Library/BaseLib/BaseLib.inf
  SynchronizationLib|MdePkg/Library/BaseSynchronizationLib/BaseSynchronizationLib.inf
  PrintLib|MdePkg/Library/BasePrintLib/BasePrintLib.inf
  CacheMaintenanceLib|MdePkg/Library/BaseCacheMaintenanceLib/BaseCacheMaintenanceLib.inf
  PeCoffLib|MdePkg/Library/BasePeCoffLib/BasePeCoffLib.inf
  PeCoffGetEntryPointLib|MdePkg/Library/BasePeCoffGetEntryPointLib/BasePeCoffGetEntryPointLib.inf
  BaseMemoryLib|MdePkg/Library/BaseMemoryLib/BaseMemoryLib.inf
  FrameBufferBltLib|MdeModulePkg/Library/FrameBufferBltLib/FrameBufferBltLib.inf

  #
  # UEFI & PI
  #
  UefiBootServicesTableLib|MdePkg/Library/UefiBootServicesTableLib/UefiBootServicesTableLib.inf
  UefiRuntimeServicesTableLib|MdePkg/Library/UefiRuntimeServicesTableLib/UefiRuntimeServicesTableLib.inf
  UefiRuntimeLib|MdePkg/Library/UefiRuntimeLib/UefiRuntimeLib.inf
  UefiLib|MdePkg/Library/UefiLib/UefiLib.inf
  UefiHiiServicesLib|MdeModulePkg/Library/UefiHiiServicesLib/UefiHiiServicesLib.inf
  HiiLib|MdeModulePkg/Library/UefiHiiLib/UefiHiiLib.inf
  DevicePathLib|MdePkg/Library/UefiDevicePathLib/UefiDevicePathLib.inf
  UefiDecompressLib|MdePkg/Library/BaseUefiDecompressLib/BaseUefiDecompressLib.inf

  PeiServicesLib|MdePkg/Library/PeiServicesLib/PeiServicesLib.inf
  DxeServicesLib|MdePkg/Library/DxeServicesLib/DxeServicesLib.inf
  DxeServicesTableLib|MdePkg/Library/DxeServicesTableLib/DxeServicesTableLib.inf
  SmbiosLib|EmulatorPkg/Library/SmbiosLib/SmbiosLib.inf

  #
  # Generic Modules
  #
  UefiScsiLib|MdePkg/Library/UefiScsiLib/UefiScsiLib.inf
  OemHookStatusCodeLib|MdeModulePkg/Library/OemHookStatusCodeLibNull/OemHookStatusCodeLibNull.inf
  BootLogoLib|MdeModulePkg/Library/BootLogoLib/BootLogoLib.inf
  FileExplorerLib|MdeModulePkg/Library/FileExplorerLib/FileExplorerLib.inf
  UefiBootManagerLib|MdeModulePkg/Library/UefiBootManagerLib/UefiBootManagerLib.inf
  BmpSupportLib|MdeModulePkg/Library/BaseBmpSupportLib/BaseBmpSupportLib.inf
  SafeIntLib|MdePkg/Library/BaseSafeIntLib/BaseSafeIntLib.inf
  CustomizedDisplayLib|MdeModulePkg/Library/CustomizedDisplayLib/CustomizedDisplayLib.inf
  SecurityManagementLib|MdeModulePkg/Library/DxeSecurityManagementLib/DxeSecurityManagementLib.inf
  TimerLib|MdePkg/Library/BaseTimerLibNullTemplate/BaseTimerLibNullTemplate.inf
  SerialPortLib|MdePkg/Library/BaseSerialPortLibNull/BaseSerialPortLibNull.inf
  CapsuleLib|MdeModulePkg/Library/DxeCapsuleLibNull/DxeCapsuleLibNull.inf
  #
  # Platform
  #
  PlatformBootManagerLib|EmulatorPkg/Library/PlatformBmLib/PlatformBmLib.inf
  KeyMapLib|EmulatorPkg/Library/KeyMapLibNull/KeyMapLibNull.inf
 
  #
  # Misc
  #
  DebugPrintErrorLevelLib|MdePkg/Library/BaseDebugPrintErrorLevelLib/BaseDebugPrintErrorLevelLib.inf
  PerformanceLib|MdePkg/Library/BasePerformanceLibNull/BasePerformanceLibNull.inf
  DebugAgentLib|MdeModulePkg/Library/DebugAgentLibNull/DebugAgentLibNull.inf
  PeiServicesTablePointerLib|EmulatorPkg/Library/PeiServicesTablePointerLibMagicPage/PeiServicesTablePointerLibMagicPage.inf
  DebugLib|MdeModulePkg/Library/PeiDxeDebugLibReportStatusCode/PeiDxeDebugLibReportStatusCode.inf
  LockBoxLib|MdeModulePkg/Library/LockBoxNullLib/LockBoxNullLib.inf
  CpuExceptionHandlerLib|MdeModulePkg/Library/CpuExceptionHandlerLibNull/CpuExceptionHandlerLibNull.inf
  TpmMeasurementLib|MdeModulePkg/Library/TpmMeasurementLibNull/TpmMeasurementLibNull.inf
  VarCheckLib|MdeModulePkg/Library/VarCheckLib/VarCheckLib.inf
  VariablePolicyLib|MdeModulePkg/Library/VariablePolicyLib/VariablePolicyLibRuntimeDxe.inf
  VariablePolicyHelperLib|MdeModulePkg/Library/VariablePolicyHelperLib/VariablePolicyHelperLib.inf
  VariableFlashInfoLib|MdeModulePkg/Library/BaseVariableFlashInfoLib/BaseVariableFlashInfoLib.inf
  SortLib|MdeModulePkg/Library/BaseSortLib/BaseSortLib.inf
  ShellLib|ShellPkg/Library/UefiShellLib/UefiShellLib.inf
  FileHandleLib|MdePkg/Library/UefiFileHandleLib/UefiFileHandleLib.inf
  PcdLib|MdePkg/Library/BasePcdLibNull/BasePcdLibNull.inf
  RegisterFilterLib|MdePkg/Library/RegisterFilterLibNull/RegisterFilterLibNull.inf

  C_BASE_LIB|C_PACKAGE/Library/C_BASE_LIB/C_BASE_LIB.inf
  C_UEFI_LIB|C_PACKAGE/Library/C_UEFI_LIB/C_UEFI_LIB.inf
  C_DXE_LIB |C_PACKAGE/Library/C_DXE_LIB/C_DXE_LIB.inf
  C_PEIM_LIB|C_PACKAGE/Library/C_PEIM_LIB/C_PEIM_LIB.inf
  C_APP_LIB|C_PACKAGE/Library/C_APP_LIB/C_APP_LIB.inf

  PrePiLib  |EmbeddedPkg/Library/PrePiLib/PrePiLib.inf

  [LibraryClasses.common.SEC]
    PeiServicesLib|EmulatorPkg/Library/SecPeiServicesLib/SecPeiServicesLib.inf
  
    PeCoffGetEntryPointLib|EmulatorPkg/Library/PeiEmuPeCoffGetEntryPointLib/PeiEmuPeCoffGetEntryPointLib.inf
    PeCoffExtraActionLib|EmulatorPkg/Library/PeiEmuPeCoffExtraActionLib/PeiEmuPeCoffExtraActionLib.inf
    SerialPortLib|EmulatorPkg/Library/PeiEmuSerialPortLib/PeiEmuSerialPortLib.inf
    PpiListLib|EmulatorPkg/Library/SecPpiListLib/SecPpiListLib.inf
    DebugLib|MdePkg/Library/BaseDebugLibSerialPort/BaseDebugLibSerialPort.inf
    TimerLib|EmulatorPkg/Library/PeiTimerLib/PeiTimerLib.inf

[LibraryClasses.common.USER_DEFINED, LibraryClasses.common.BASE]
    DebugLib|MdePkg/Library/BaseDebugLibNull/BaseDebugLibNull.inf
    PeCoffExtraActionLib|MdePkg/Library/BasePeCoffExtraActionLibNull/BasePeCoffExtraActionLibNull.inf
    MemoryAllocationLib|MdePkg/Library/PeiMemoryAllocationLib/PeiMemoryAllocationLib.inf
    PcdLib|MdePkg/Library/BasePcdLibNull/BasePcdLibNull.inf
    PpiListLib|EmulatorPkg/Library/SecPpiListLib/SecPpiListLib.inf
    ThunkPpiList|EmulatorPkg/Library/ThunkPpiList/ThunkPpiList.inf
    ThunkProtocolList|EmulatorPkg/Library/ThunkProtocolList/ThunkProtocolList.inf
    PeCoffGetEntryPointLib|MdePkg/Library/BasePeCoffGetEntryPointLib/BasePeCoffGetEntryPointLib.inf
    PpiListLib|EmulatorPkg/Library/SecPpiListLib/SecPpiListLib.inf
    PeiServicesLib|EmulatorPkg/Library/SecPeiServicesLib/SecPeiServicesLib.inf
    

  [LibraryClasses.common.DXE_RUNTIME_DRIVER, LibraryClasses.common.UEFI_DRIVER, LibraryClasses.common.DXE_DRIVER, LibraryClasses.common.UEFI_APPLICATION]
    HobLib|MdePkg/Library/DxeHobLib/DxeHobLib.inf
    PcdLib|MdePkg/Library/DxePcdLib/DxePcdLib.inf
    MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf
    ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
    EmuThunkLib|EmulatorPkg/Library/DxeEmuLib/DxeEmuLib.inf
    PeCoffExtraActionLib|EmulatorPkg/Library/DxeEmuPeCoffExtraActionLib/DxeEmuPeCoffExtraActionLib.inf
    ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
    TimerLib|EmulatorPkg/Library/DxeTimerLib/DxeTimerLib.inf

  [LibraryClasses.common.PEIM, LibraryClasses.common.PEI_CORE]
    HobLib|MdePkg/Library/PeiHobLib/PeiHobLib.inf
    MemoryAllocationLib|MdePkg/Library/PeiMemoryAllocationLib/PeiMemoryAllocationLib.inf
    PeCoffGetEntryPointLib|EmulatorPkg/Library/PeiEmuPeCoffGetEntryPointLib/PeiEmuPeCoffGetEntryPointLib.inf
    PeCoffExtraActionLib|EmulatorPkg/Library/PeiEmuPeCoffExtraActionLib/PeiEmuPeCoffExtraActionLib.inf
    ExtractGuidedSectionLib|MdePkg/Library/PeiExtractGuidedSectionLib/PeiExtractGuidedSectionLib.inf
    SerialPortLib|EmulatorPkg/Library/PeiEmuSerialPortLib/PeiEmuSerialPortLib.inf
    ReportStatusCodeLib|MdeModulePkg/Library/PeiReportStatusCodeLib/PeiReportStatusCodeLib.inf
    TimerLib|EmulatorPkg/Library/PeiTimerLib/PeiTimerLib.inf

[PcdsFixedAtBuild.common]
  gEfiChapter7TokenSpaceGuid.C_DXE_Demo|0x9