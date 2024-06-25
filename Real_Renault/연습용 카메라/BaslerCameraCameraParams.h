//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------

/*!
\file
\brief A parameter class containing all parameters as members that are available for acA2440-20gc

Sources:
acA2440-20gc 107213-21;U;acA2440_20g;V2.1-0;1
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------

#ifndef BASLER_PYLON_BASLERCAMERACAMERAPARAMS_H
#define BASLER_PYLON_BASLERCAMERACAMERAPARAMS_H

#pragma once

// common parameter types
#include <pylon/ParameterIncludes.h>
#include <pylon/EnumParameterT.h>

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4250 ) // warning C4250: 'Pylon::CXYZParameter': inherits 'Pylon::CParameter::Pylon::CParameter::ZYX' via dominance
#endif

//! The namespace containing the a control interface and related enumeration types for acA2440-20gc
namespace Pylon
{
namespace BaslerCameraCameraParams_Params
{
    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    //! Valid values for AcquisitionMode
    enum AcquisitionModeEnums
    {
        AcquisitionMode_Continuous,  //!< The acquisition mode is set to Continuous - Applies to: acA2440-20gc
        AcquisitionMode_SingleFrame  //!< The acquisition mode is set to Single Frame - Applies to: acA2440-20gc
    };

    //! Valid values for AcquisitionStatusSelector
    enum AcquisitionStatusSelectorEnums
    {
        AcquisitionStatusSelector_AcquisitionActive,  //!< A check determines whether the camera is currently acquiring one or multiple frames - Applies to: acA2440-20gc
        AcquisitionStatusSelector_AcquisitionTransfer,  //!< A check determines whether the camera is currently transferring an acquisition of one or multiple frames - Applies to: acA2440-20gc
        AcquisitionStatusSelector_AcquisitionTriggerWait,  //!< A check determines whether the camera is currently waiting for a trigger to acquire one or multiple frames - Applies to: acA2440-20gc
        AcquisitionStatusSelector_ExposureActive,  //!< A check determines whether the camera is currently exposing a frame - Applies to: acA2440-20gc
        AcquisitionStatusSelector_FrameActive,  //!< A check determines whether the camera is currently capturing a frame - Applies to: acA2440-20gc
        AcquisitionStatusSelector_FrameTransfer,  //!< A check determines whether the camera is currently transferring a frame - Applies to: acA2440-20gc
        AcquisitionStatusSelector_FrameTriggerWait,  //!< A check determines whether the camera is currently waiting for a frame trigger - Applies to: acA2440-20gc
        AcquisitionStatusSelector_LineTriggerWait  //!< A check determines whether the camera is currently waiting for a line trigger - Applies to: acA2440-20gc
    };

    //! Valid values for AutoFunctionAOISelector
    enum AutoFunctionAOISelectorEnums
    {
        AutoFunctionAOISelector_AOI1,  //!< Auto function AOI 1 can be configured - Applies to: acA2440-20gc
        AutoFunctionAOISelector_AOI2  //!< Auto function AOI 2 can be configured - Applies to: acA2440-20gc
    };

    //! Valid values for AutoFunctionProfile
    enum AutoFunctionProfileEnums
    {
        AutoFunctionProfile_ExposureMinimum,  //!< Exposure time is kept as low as possible - Applies to: acA2440-20gc
        AutoFunctionProfile_GainMinimum  //!< Gain is kept as low as possible - Applies to: acA2440-20gc
    };

    //! Valid values for BLCSerialPortBaudRate
    enum BLCSerialPortBaudRateEnums
    {
        BLCSerialPortBaudRate_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for BLCSerialPortParity
    enum BLCSerialPortParityEnums
    {
        BLCSerialPortParity_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for BLCSerialPortSource
    enum BLCSerialPortSourceEnums
    {
        BLCSerialPortSource_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for BLCSerialPortStopBits
    enum BLCSerialPortStopBitsEnums
    {
        BLCSerialPortStopBits_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for BLCSerialReceiveQueueStatus
    enum BLCSerialReceiveQueueStatusEnums
    {
        BLCSerialReceiveQueueStatus_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for BLCSerialTransmitQueueStatus
    enum BLCSerialTransmitQueueStatusEnums
    {
        BLCSerialTransmitQueueStatus_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for BalanceRatioSelector
    enum BalanceRatioSelectorEnums
    {
        BalanceRatioSelector_Blue,  //!< Balance ratio is applied to the blue channel - Applies to: acA2440-20gc
        BalanceRatioSelector_Green,  //!< Balance ratio is applied to the green channel - Applies to: acA2440-20gc
        BalanceRatioSelector_Red  //!< Balance ratio is applied to the red channel - Applies to: acA2440-20gc
    };

    //! Valid values for BalanceWhiteAuto
    enum BalanceWhiteAutoEnums
    {
        BalanceWhiteAuto_Continuous,  //!< White balance is adjusted continuously while images are being acquired - Applies to: acA2440-20gc
        BalanceWhiteAuto_Off,  //!< The Balance White Auto auto function is disabled - Applies to: acA2440-20gc
        BalanceWhiteAuto_Once  //!< White balance is adjusted automatically to reach the specified target value - Applies to: acA2440-20gc
    };

    //! Valid values for BinningHorizontalMode
    enum BinningHorizontalModeEnums
    {
        BinningHorizontalMode_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for BinningVerticalMode
    enum BinningVerticalModeEnums
    {
        BinningVerticalMode_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for BlackLevelSelector
    enum BlackLevelSelectorEnums
    {
        BlackLevelSelector_All  //!< The black level value is applied to all sensor taps - Applies to: acA2440-20gc
    };

    //! Valid values for BslContrastMode
    enum BslContrastModeEnums
    {
        BslContrastMode_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for BslLightControlErrorStatus
    enum BslLightControlErrorStatusEnums
    {
        BslLightControlErrorStatus_Device1,  //!< Light device 1 is experiencing problems - Applies to: acA2440-20gc
        BslLightControlErrorStatus_Device2,  //!< Light device 2 is experiencing problems - Applies to: acA2440-20gc
        BslLightControlErrorStatus_Device3,  //!< Light device 3 is experiencing problems - Applies to: acA2440-20gc
        BslLightControlErrorStatus_Device4,  //!< Light device 4 is experiencing problems - Applies to: acA2440-20gc
        BslLightControlErrorStatus_MultipleDevices,  //!< Multiple light devices are experiencing problems - Applies to: acA2440-20gc
        BslLightControlErrorStatus_NoError  //!< No error was detected - Applies to: acA2440-20gc
    };

    //! Valid values for BslLightControlMode
    enum BslLightControlModeEnums
    {
        BslLightControlMode_Off,  //!< The light control features are disabled - Applies to: acA2440-20gc
        BslLightControlMode_On  //!< The light control features are enabled - Applies to: acA2440-20gc
    };

    //! Valid values for BslLightControlSource
    enum BslLightControlSourceEnums
    {
        BslLightControlSource_Line3,  //!< Line 3 is used to control the light features - Applies to: acA2440-20gc
        BslLightControlSource_Off  //!< No line is used to control the light features - Applies to: acA2440-20gc
    };

    //! Valid values for BslLightControlStatus
    enum BslLightControlStatusEnums
    {
        BslLightControlStatus_Idle,  //!< No light device has been detected - Applies to: acA2440-20gc
        BslLightControlStatus_Off,  //!< The light control mode is disabled - Applies to: acA2440-20gc
        BslLightControlStatus_Ready,  //!< The light device is ready for use - Applies to: acA2440-20gc
        BslLightControlStatus_Searching,  //!< The controller ist searching for light devices connected to your camera - Applies to: acA2440-20gc
        BslLightControlStatus_Updating  //!< Parameters are being updated - Applies to: acA2440-20gc
    };

    //! Valid values for BslLightControlTriggerMode
    enum BslLightControlTriggerModeEnums
    {
        BslLightControlTriggerMode_ExposureActive,  //!< The Exposure Active signal is used to trigger the light in strobe mode - Applies to: acA2440-20gc
        BslLightControlTriggerMode_FlashWindow  //!< The Flash Window signal is used to trigger the light in strobe mode - Applies to: acA2440-20gc
    };

    //! Valid values for BslLightDeviceChangeID
    enum BslLightDeviceChangeIDEnums
    {
        BslLightDeviceChangeID_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for BslLightDeviceControlMode
    enum BslLightDeviceControlModeEnums
    {
        BslLightDeviceControlMode_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for BslLightDeviceLastError
    enum BslLightDeviceLastErrorEnums
    {
        BslLightDeviceLastError_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for BslLightDeviceOperationMode
    enum BslLightDeviceOperationModeEnums
    {
        BslLightDeviceOperationMode_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for BslLightDeviceSelector
    enum BslLightDeviceSelectorEnums
    {
        BslLightDeviceSelector_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for BslLightDeviceStrobeMode
    enum BslLightDeviceStrobeModeEnums
    {
        BslLightDeviceStrobeMode_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for ChunkPixelFormat
    enum ChunkPixelFormatEnums
    {
        ChunkPixelFormat_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for ChunkSelector
    enum ChunkSelectorEnums
    {
        ChunkSelector_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for ColorAdjustmentSelector
    enum ColorAdjustmentSelectorEnums
    {
        ColorAdjustmentSelector_Blue,  //!< Colors with a predominant blue component can be adjusted - Applies to: acA2440-20gc
        ColorAdjustmentSelector_Cyan,  //!< Colors with a predominant cyan component can be adjusted - Applies to: acA2440-20gc
        ColorAdjustmentSelector_Green,  //!< Colors with a predominant green component can be adjusted - Applies to: acA2440-20gc
        ColorAdjustmentSelector_Magenta,  //!< Colors with a predominant magenta component can be adjusted - Applies to: acA2440-20gc
        ColorAdjustmentSelector_Red,  //!< Colors with a predominant red component can be adjusted - Applies to: acA2440-20gc
        ColorAdjustmentSelector_Yellow  //!< Colors with a predominant yellow component can be adjusted - Applies to: acA2440-20gc
    };

    //! Valid values for ColorTransformationSelector
    enum ColorTransformationSelectorEnums
    {
        ColorTransformationSelector_RGBtoRGB  //!< Color transformation from RGB to RGB will be performed - Applies to: acA2440-20gc
    };

    //! Valid values for ColorTransformationValueSelector
    enum ColorTransformationValueSelectorEnums
    {
        ColorTransformationValueSelector_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for CounterEventSource
    enum CounterEventSourceEnums
    {
        CounterEventSource_FrameTrigger  //!< The selected counter counts the number of Frame Trigger events - Applies to: acA2440-20gc
    };

    //! Valid values for CounterResetSource
    enum CounterResetSourceEnums
    {
        CounterResetSource_Line1,  //!< The selected counter can be reset by a signal applied to Line 1 - Applies to: acA2440-20gc
        CounterResetSource_Line3,  //!< The selected counter can be reset by a signal applied to Line 3 - Applies to: acA2440-20gc
        CounterResetSource_Off,  //!< The counter reset is disabled - Applies to: acA2440-20gc
        CounterResetSource_Software  //!< The selected counter can be reset by a software command - Applies to: acA2440-20gc
    };

    //! Valid values for CounterSelector
    enum CounterSelectorEnums
    {
        CounterSelector_Counter1,  //!< Counter 1 can be configured - Applies to: acA2440-20gc
        CounterSelector_Counter2  //!< Counter 2 can be configured - Applies to: acA2440-20gc
    };

    //! Valid values for DemosaicingMode
    enum DemosaicingModeEnums
    {
        DemosaicingMode_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for DeviceScanType
    enum DeviceScanTypeEnums
    {
        DeviceScanType_Areascan,  //!< The camera has an area scan sensor - Applies to: acA2440-20gc
        DeviceScanType_Linescan  //!< The camera has a line scan sensor - Applies to: acA2440-20gc
    };

    //! Valid values for EventNotification
    enum EventNotificationEnums
    {
        EventNotification_GenICamEvent,  //!< Event notifications are enabled and the notification type is set to GenICam - Applies to: acA2440-20gc
        EventNotification_Off,  //!< Event notifications are disabled - Applies to: acA2440-20gc
        EventNotification_On  //!< Event notifications are enabled - Applies to: acA2440-20gc
    };

    //! Valid values for EventSelector
    enum EventSelectorEnums
    {
        EventSelector_AcquisitionStart,  //!< Event notifications for the Acquisition Start event can be enabled - Applies to: acA2440-20gc
        EventSelector_AcquisitionStartOvertrigger,  //!< Event notifications for the Acquisition Start Overtrigger event can be enabled - Applies to: acA2440-20gc
        EventSelector_AcquisitionStartWait,  //!< Event notifications for the Acquisition Start Wait event can be enabled - Applies to: acA2440-20gc
        EventSelector_ActionLate,  //!< Event notifications for the Action Late event can be enabled - Applies to: acA2440-20gc
        EventSelector_CriticalTemperature,  //!< Event notifications for the Critical Temperature event can be enabled - Applies to: acA2440-20gc
        EventSelector_EventOverrun,  //!< Event notifications for the Event Overrun event can be enabled - Applies to: acA2440-20gc
        EventSelector_ExposureEnd,  //!< Event notifications for the Exposure End event can be enabled - Applies to: acA2440-20gc
        EventSelector_FrameStart,  //!< Event notifications for the Frame Start event can be enabled - Applies to: acA2440-20gc
        EventSelector_FrameStartOvertrigger,  //!< Event notifications for the Frame Start Overtrigger event can be enabled - Applies to: acA2440-20gc
        EventSelector_FrameStartWait,  //!< Event notifications for the Frame Start Wait event can be enabled - Applies to: acA2440-20gc
        EventSelector_OverTemperature  //!< Event notifications for the Over Temperature event can be enabled - Applies to: acA2440-20gc
    };

    //! Valid values for ExpertFeatureAccessSelector
    enum ExpertFeatureAccessSelectorEnums
    {
        ExpertFeatureAccessSelector_ExpertFeature1,  //!< Expert Feature 1 can be configured - Applies to: acA2440-20gc
        ExpertFeatureAccessSelector_ExpertFeature10,  //!< Expert Feature 10 can be configured - Applies to: acA2440-20gc
        ExpertFeatureAccessSelector_ExpertFeature11,  //!< Expert feature 11 can be configured - Applies to: acA2440-20gc
        ExpertFeatureAccessSelector_ExpertFeature1_Legacy,  //!< Expert Feature 1 (legacy) can be configured - Applies to: acA2440-20gc
        ExpertFeatureAccessSelector_ExpertFeature2,  //!< Expert Feature 2 can be configured - Applies to: acA2440-20gc
        ExpertFeatureAccessSelector_ExpertFeature3,  //!< Expert Feature 3 can be configured - Applies to: acA2440-20gc
        ExpertFeatureAccessSelector_ExpertFeature4,  //!< Expert Feature 4 can be configured - Applies to: acA2440-20gc
        ExpertFeatureAccessSelector_ExpertFeature5,  //!< Expert Feature 5 can be configured - Applies to: acA2440-20gc
        ExpertFeatureAccessSelector_ExpertFeature6,  //!< Expert Feature 6 can be configured - Applies to: acA2440-20gc
        ExpertFeatureAccessSelector_ExpertFeature7,  //!< Expert Feature 7 can be configured - Applies to: acA2440-20gc
        ExpertFeatureAccessSelector_ExpertFeature8,  //!< Expert Feature 8 can be configured - Applies to: acA2440-20gc
        ExpertFeatureAccessSelector_ExpertFeature9  //!< Expert Feature 9 can be configured - Applies to: acA2440-20gc
    };

    //! Valid values for ExposureAuto
    enum ExposureAutoEnums
    {
        ExposureAuto_Continuous,  //!< The exposure time is adjusted continuously while images are being acquired - Applies to: acA2440-20gc
        ExposureAuto_Off,  //!< Automatic exposure time adjustment is disabled - Applies to: acA2440-20gc
        ExposureAuto_Once  //!< The exposure time is adjusted automatically to reach the specified target value - Applies to: acA2440-20gc
    };

    //! Valid values for ExposureMode
    enum ExposureModeEnums
    {
        ExposureMode_Timed,  //!< The exposure mode is set to Timed - Applies to: acA2440-20gc
        ExposureMode_TriggerWidth  //!< The exposure mode is set to Trigger Width - Applies to: acA2440-20gc
    };

    //! Valid values for ExposureOverlapTimeMode
    enum ExposureOverlapTimeModeEnums
    {
        ExposureOverlapTimeMode_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for ExposureTimeMode
    enum ExposureTimeModeEnums
    {
        ExposureTimeMode_Standard,  //!< The exposure time mode is set to Standard - Applies to: acA2440-20gc
        ExposureTimeMode_UltraShort  //!< The exposure time mode is set to Ultra Short - Applies to: acA2440-20gc
    };

    //! Valid values for FileOpenMode
    enum FileOpenModeEnums
    {
        FileOpenMode_Read,  //!< Files are opened in read-only mode - Applies to: acA2440-20gc
        FileOpenMode_Write  //!< Files are opened in write-only mode - Applies to: acA2440-20gc
    };

    //! Valid values for FileOperationSelector
    enum FileOperationSelectorEnums
    {
        FileOperationSelector_Close,  //!< The currently selected file can be closed - Applies to: acA2440-20gc
        FileOperationSelector_Open,  //!< The currently selected file can be opened - Applies to: acA2440-20gc
        FileOperationSelector_Read,  //!< The currently selected file can be read - Applies to: acA2440-20gc
        FileOperationSelector_Write  //!< The currently selected file can be written to - Applies to: acA2440-20gc
    };

    //! Valid values for FileOperationStatus
    enum FileOperationStatusEnums
    {
        FileOperationStatus_Failure,  //!< The file operation has failed - Applies to: acA2440-20gc
        FileOperationStatus_Success  //!< The file operation was successful - Applies to: acA2440-20gc
    };

    //! Valid values for FileSelector
    enum FileSelectorEnums
    {
        FileSelector_ExpertFeature7File,  //!< The Expert Feature 7 File file is selected - Applies to: acA2440-20gc
        FileSelector_UserData,  //!< The User Data file is selected - Applies to: acA2440-20gc
        FileSelector_UserGainShading1,  //!< The User Gain Shading 1 file is selected - Applies to: acA2440-20gc
        FileSelector_UserGainShading2,  //!< The User Gain Shading 2 file is selected - Applies to: acA2440-20gc
        FileSelector_UserOffsetShading1,  //!< The User Offset Shading 1 file is selected - Applies to: acA2440-20gc
        FileSelector_UserOffsetShading2,  //!< The User Offset Shading 2 file is selected - Applies to: acA2440-20gc
        FileSelector_UserSet1,  //!< The User Set 1 file is selected - Applies to: acA2440-20gc
        FileSelector_UserSet2,  //!< The User Set 2 file is selected - Applies to: acA2440-20gc
        FileSelector_UserSet3,  //!< The User Set 3 file is selected - Applies to: acA2440-20gc
        FileSelector_VignettingCorrection  //!< The 'VignettingCorrection' file is set - Applies to: acA2440-20gc
    };

    //! Valid values for GainAuto
    enum GainAutoEnums
    {
        GainAuto_Continuous,  //!< The gain is adjusted continuously while images are being acquired - Applies to: acA2440-20gc
        GainAuto_Off,  //!< Automatic gain adjustment is disabled - Applies to: acA2440-20gc
        GainAuto_Once  //!< The gain is adjusted automatically to reach the specifed target value - Applies to: acA2440-20gc
    };

    //! Valid values for GainSelector
    enum GainSelectorEnums
    {
        GainSelector_All  //!< Changes to the gain will be applied universally - Applies to: acA2440-20gc
    };

    //! Valid values for GammaSelector
    enum GammaSelectorEnums
    {
        GammaSelector_User,  //!< The gamma curve can be configured by the user - Applies to: acA2440-20gc
        GammaSelector_sRGB  //!< The gamma curve is set to a fixed sRGB curve - Applies to: acA2440-20gc
    };

    //! Valid values for GevCCP
    enum GevCCPEnums
    {
        GevCCP_Control,  //!< The control channel privilege is set to Control - Applies to: acA2440-20gc
        GevCCP_Exclusive,  //!< The control channel privilege is set to Exclusive - Applies to: acA2440-20gc
        GevCCP_ExclusiveControl  //!< The control channel privilege is set to Exclusive Control - Applies to: acA2440-20gc
    };

    //! Valid values for GevGVSPExtendedIDMode
    enum GevGVSPExtendedIDModeEnums
    {
        GevGVSPExtendedIDMode_Off,  //!< The Extended ID mode is switched off - Applies to: acA2440-20gc
        GevGVSPExtendedIDMode_On  //!< The Extended ID mode is switched on - Applies to: acA2440-20gc
    };

    //! Valid values for GevIEEE1588Status
    enum GevIEEE1588StatusEnums
    {
        GevIEEE1588Status_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for GevIEEE1588StatusLatched
    enum GevIEEE1588StatusLatchedEnums
    {
        GevIEEE1588StatusLatched_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for GevInterfaceSelector
    enum GevInterfaceSelectorEnums
    {
        GevInterfaceSelector_NetworkInterface0  //!< Network interface 0 can be configured - Applies to: acA2440-20gc
    };

    //! Valid values for GevStreamChannelSelector
    enum GevStreamChannelSelectorEnums
    {
        GevStreamChannelSelector_StreamChannel0  //!< Stream channel 0 can be configured - Applies to: acA2440-20gc
    };

    //! Valid values for LUTSelector
    enum LUTSelectorEnums
    {
        LUTSelector_Luminance  //!< The luminance lookup table can be configured - Applies to: acA2440-20gc
    };

    //! Valid values for LastError
    enum LastErrorEnums
    {
        LastError_InsufficientTriggerWidth,  //!< The trigger width was too short - Applies to: acA2440-20gc
        LastError_InvalidParameter,  //!< A parameter was set to an invalid value - Applies to: acA2440-20gc
        LastError_NoError,  //!< No error was detected - Applies to: acA2440-20gc
        LastError_OverTemperature,  //!< An over temperature state has been detected - Applies to: acA2440-20gc
        LastError_Overtrigger,  //!< The camera was overtriggered - Applies to: acA2440-20gc
        LastError_PowerFailure,  //!< The power supply is not sufficient - Applies to: acA2440-20gc
        LastError_UserDefPixFailure,  //!< An error was detected while loading user defect pixel data - Applies to: acA2440-20gc
        LastError_Userset  //!< An error was detected while loading a user set - Applies to: acA2440-20gc
    };

    //! Valid values for LightSourceSelector
    enum LightSourceSelectorEnums
    {
        LightSourceSelector_Custom,  //!< The color transformation matrix can be customized - Applies to: acA2440-20gc
        LightSourceSelector_Daylight,  //!< The color transformation matrix is optimized for image acquisitions with daylight of 5000 K - Applies to: acA2440-20gc
        LightSourceSelector_Daylight6500K,  //!< The color transformation matrix is optimized for image acquisitions with daylight of 6500 K - Applies to: acA2440-20gc
        LightSourceSelector_Off,  //!< No color transformation for a specific light source is performed - Applies to: acA2440-20gc
        LightSourceSelector_Tungsten  //!< The color transformation matrix is optimized for image acquisition with tungsten incandescent light (3100 K) - Applies to: acA2440-20gc
    };

    //! Valid values for LineFormat
    enum LineFormatEnums
    {
        LineFormat_LVDS,  //!< The line is currently accepting or sending LVDS level signals - Applies to: acA2440-20gc
        LineFormat_NoConnect,  //!< The line is not connected - Applies to: acA2440-20gc
        LineFormat_OptoCoupled,  //!< The line is opto-coupled - Applies to: acA2440-20gc
        LineFormat_RS422,  //!< The line is currently accepting or sending RS-422 level signals - Applies to: acA2440-20gc
        LineFormat_TTL,  //!< The line is currently accepting or sending TTL level signals - Applies to: acA2440-20gc
        LineFormat_TriState  //!< The line is currently in tri-state mode (not driven) - Applies to: acA2440-20gc
    };

    //! Valid values for LineLogic
    enum LineLogicEnums
    {
        LineLogic_Negative,  //!< The line logic of the currently selected line is negative - Applies to: acA2440-20gc
        LineLogic_Positive  //!< The line logic of the currently selected line is positive - Applies to: acA2440-20gc
    };

    //! Valid values for LineMode
    enum LineModeEnums
    {
        LineMode_Input,  //!< The selected physical line can be used to input an electrical signal - Applies to: acA2440-20gc
        LineMode_Output  //!< The selected physical line can be used to output an electrical signal - Applies to: acA2440-20gc
    };

    //! Valid values for LineSelector
    enum LineSelectorEnums
    {
        LineSelector_Line1,  //!< Line 1 can be configured - Applies to: acA2440-20gc
        LineSelector_Line2,  //!< Line 2 can be configured - Applies to: acA2440-20gc
        LineSelector_Line3  //!< Line 3 can be configured - Applies to: acA2440-20gc
    };

    //! Valid values for LineSource
    enum LineSourceEnums
    {
        LineSource_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for ParameterSelector
    enum ParameterSelectorEnums
    {
        ParameterSelector_AutoTargetValue,  //!< The factory limits of the Auto Target Value parameter can be removed - Applies to: acA2440-20gc
        ParameterSelector_Gain  //!< The factory limits of the Gain parameter can be removed - Applies to: acA2440-20gc
    };

    //! Valid values for PgiMode
    enum PgiModeEnums
    {
        PgiMode_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for PixelColorFilter
    enum PixelColorFilterEnums
    {
        PixelColorFilter_Bayer_BG,  //!< The Bayer filter has a BG/GR alignment to the pixels in the acquired images - Applies to: acA2440-20gc
        PixelColorFilter_Bayer_GB,  //!< The Bayer filter has a GB/RG alignment to the pixels in the acquired images - Applies to: acA2440-20gc
        PixelColorFilter_Bayer_GR,  //!< The Bayer filter has a GR/BG alignment to the pixels in the acquired images - Applies to: acA2440-20gc
        PixelColorFilter_Bayer_RG,  //!< The Bayer filter has an RG/GB alignment to the pixels in the acquired images - Applies to: acA2440-20gc
        PixelColorFilter_None  //!< The camera doesn't have a Bayer filter - Applies to: acA2440-20gc
    };

    //! Valid values for PixelFormat
    enum PixelFormatEnums
    {
        PixelFormat_BayerBG12,  //!< The pixel format is set to Bayer BG 12 - Applies to: acA2440-20gc
        PixelFormat_BayerBG12Packed,  //!< The pixel format is set to Bayer BG 12 Packed - Applies to: acA2440-20gc
        PixelFormat_BayerBG8,  //!< The pixel format is set to Bayer BG 8 - Applies to: acA2440-20gc
        PixelFormat_BayerGB12,  //!< The pixel format is set to Bayer GB 12 - Applies to: acA2440-20gc
        PixelFormat_BayerGB12Packed,  //!< The pixel format is set to Bayer GB 12 Packed - Applies to: acA2440-20gc
        PixelFormat_BayerGB8,  //!< The pixel format is set to Bayer GB 8 - Applies to: acA2440-20gc
        PixelFormat_BayerGR12,  //!< The pixel format is set to Bayer GR 12 - Applies to: acA2440-20gc
        PixelFormat_BayerGR12Packed,  //!< The pixel format is set to Bayer GR 12 Packed - Applies to: acA2440-20gc
        PixelFormat_BayerGR8,  //!< The pixel format is set to Bayer GR 8 - Applies to: acA2440-20gc
        PixelFormat_BayerRG12,  //!< The pixel format is set to Bayer RG 12 - Applies to: acA2440-20gc
        PixelFormat_BayerRG12Packed,  //!< The pixel format is set to Bayer RG 12 Packed - Applies to: acA2440-20gc
        PixelFormat_BayerRG8,  //!< The pixel format is set to Bayer RG 8 - Applies to: acA2440-20gc
        PixelFormat_Mono8,  //!< The pixel format is set to Mono 8 - Applies to: acA2440-20gc
        PixelFormat_YUV422Packed,  //!< The pixel format is set to YUV 422 Packed - Applies to: acA2440-20gc
        PixelFormat_YUV422_YUYV_Packed  //!< The pixel format is set to YUV 422 (YUYV) Packed - Applies to: acA2440-20gc
    };

    //! Valid values for PixelSize
    enum PixelSizeEnums
    {
        PixelSize_Bpp1,  //!< The pixel depth in the acquired images is 1 bit per pixel - Applies to: acA2440-20gc
        PixelSize_Bpp10,  //!< The pixel depth in the acquired images is 10 bits per pixel - Applies to: acA2440-20gc
        PixelSize_Bpp12,  //!< The pixel depth in the acquired images is 12 bits per pixel - Applies to: acA2440-20gc
        PixelSize_Bpp16,  //!< The pixel depth in the acquired images is 16 bits per pixel - Applies to: acA2440-20gc
        PixelSize_Bpp2,  //!< The pixel depth in the acquired images is 2 bits per pixel - Applies to: acA2440-20gc
        PixelSize_Bpp24,  //!< The pixel depth in the acquired images is 24 bits per pixel - Applies to: acA2440-20gc
        PixelSize_Bpp32,  //!< The pixel depth in the acquired images is 32 bits per pixel - Applies to: acA2440-20gc
        PixelSize_Bpp36,  //!< The pixel depth in the acquired images is 36 bits per pixel - Applies to: acA2440-20gc
        PixelSize_Bpp4,  //!< The pixel depth in the acquired images is 4 bits per pixel - Applies to: acA2440-20gc
        PixelSize_Bpp48,  //!< The pixel depth in the acquired images is 48 bits per pixel - Applies to: acA2440-20gc
        PixelSize_Bpp8  //!< The pixel depth in the acquired images is 8 bits per pixel - Applies to: acA2440-20gc
    };

    //! Valid values for ROIZoneMode
    enum ROIZoneModeEnums
    {
        ROIZoneMode_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for ROIZoneSelector
    enum ROIZoneSelectorEnums
    {
        ROIZoneSelector_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for SensorReadoutMode
    enum SensorReadoutModeEnums
    {
        SensorReadoutMode_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for SequenceAddressBitSelector
    enum SequenceAddressBitSelectorEnums
    {
        SequenceAddressBitSelector_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for SequenceAddressBitSource
    enum SequenceAddressBitSourceEnums
    {
        SequenceAddressBitSource_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for SequenceAdvanceMode
    enum SequenceAdvanceModeEnums
    {
        SequenceAdvanceMode_Auto,  //!< The Auto sequence advance mode is selected - Applies to: acA2440-20gc
        SequenceAdvanceMode_Controlled,  //!< The Controlled sequence advance mode is selected - Applies to: acA2440-20gc
        SequenceAdvanceMode_FreeSelection  //!< The Free Selection sequence advance mode is selected - Applies to: acA2440-20gc
    };

    //! Valid values for SequenceConfigurationMode
    enum SequenceConfigurationModeEnums
    {
        SequenceConfigurationMode_Off,  //!< The sequencer can't be configured - Applies to: acA2440-20gc
        SequenceConfigurationMode_On  //!< The sequencer can be configured - Applies to: acA2440-20gc
    };

    //! Valid values for SequenceControlSelector
    enum SequenceControlSelectorEnums
    {
        SequenceControlSelector_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for SequenceControlSource
    enum SequenceControlSourceEnums
    {
        SequenceControlSource_Todo  //!< TODO - Applies to: acA2440-20gc
    };

    //! Valid values for ShutterMode
    enum ShutterModeEnums
    {
        ShutterMode_Global  //!< The shutter opens and closes at the same time for all pixels - Applies to: acA2440-20gc
    };

    //! Valid values for SyncUserOutputSelector
    enum SyncUserOutputSelectorEnums
    {
        SyncUserOutputSelector_SyncUserOutput1,  //!< User-settable synchronous output signal 1 can be configured - Applies to: acA2440-20gc
        SyncUserOutputSelector_SyncUserOutput2  //!< User-settable synchronous output signal 2 can be configured - Applies to: acA2440-20gc
    };

    //! Valid values for TemperatureSelector
    enum TemperatureSelectorEnums
    {
        TemperatureSelector_Coreboard  //!< The temperature is measured on the core board - Applies to: acA2440-20gc
    };

    //! Valid values for TemperatureState
    enum TemperatureStateEnums
    {
        TemperatureState_Critical,  //!< The temperature is critical - Applies to: acA2440-20gc
        TemperatureState_Error,  //!< The temperature state could not be retrieved - Applies to: acA2440-20gc
        TemperatureState_Ok  //!< The temperature is normal - Applies to: acA2440-20gc
    };

    //! Valid values for TestImageSelector
    enum TestImageSelectorEnums
    {
        TestImageSelector_Off,  //!< The camera doesn't display a test image - Applies to: acA2440-20gc
        TestImageSelector_Testimage1,  //!< The camera generates a test image with the test image 1 pattern - Applies to: acA2440-20gc
        TestImageSelector_Testimage2,  //!< The camera generates a test image with the test image 2 pattern - Applies to: acA2440-20gc
        TestImageSelector_Testimage3,  //!< The camera generates a test image with the test image 3 pattern - Applies to: acA2440-20gc
        TestImageSelector_Testimage4,  //!< The camera generates a test image with the test image 4 pattern - Applies to: acA2440-20gc
        TestImageSelector_Testimage5,  //!< The camera generates a test image with the test image 5 pattern - Applies to: acA2440-20gc
        TestImageSelector_Testimage6  //!< The camera generates a test image with the test image 6 pattern - Applies to: acA2440-20gc
    };

    //! Valid values for TimerSelector
    enum TimerSelectorEnums
    {
        TimerSelector_Timer1  //!< Timer 1 can be configured - Applies to: acA2440-20gc
    };

    //! Valid values for TimerTriggerActivation
    enum TimerTriggerActivationEnums
    {
        TimerTriggerActivation_RisingEdge  //!< The timer will start at a rising edge signal change - Applies to: acA2440-20gc
    };

    //! Valid values for TimerTriggerSource
    enum TimerTriggerSourceEnums
    {
        TimerTriggerSource_ExposureStart  //!< The timer will start at an Exposure Start signal - Applies to: acA2440-20gc
    };

    //! Valid values for TriggerActivation
    enum TriggerActivationEnums
    {
        TriggerActivation_FallingEdge,  //!< The selected trigger is activated by the falling edge of the source signal - Applies to: acA2440-20gc
        TriggerActivation_RisingEdge  //!< The selected trigger is activated by the rising edge of the source signal - Applies to: acA2440-20gc
    };

    //! Valid values for TriggerMode
    enum TriggerModeEnums
    {
        TriggerMode_Off,  //!< The currently selected trigger is turned off - Applies to: acA2440-20gc
        TriggerMode_On  //!< The currently selected trigger is turned on - Applies to: acA2440-20gc
    };

    //! Valid values for TriggerSelector
    enum TriggerSelectorEnums
    {
        TriggerSelector_AcquisitionStart,  //!< The Acquisition Start trigger can be configured - Applies to: acA2440-20gc
        TriggerSelector_FrameStart  //!< The Frame Start trigger can be configured - Applies to: acA2440-20gc
    };

    //! Valid values for TriggerSource
    enum TriggerSourceEnums
    {
        TriggerSource_Action1,  //!< The source signal for the selected trigger is set to action command signal 1 - Applies to: acA2440-20gc
        TriggerSource_Line1,  //!< The source signal for the selected trigger is set to Line 1 - Applies to: acA2440-20gc
        TriggerSource_Line3,  //!< The source signal for the selected trigger is set to Line 3 - Applies to: acA2440-20gc
        TriggerSource_Software  //!< The source signal for the selected trigger is set to software triggering - Applies to: acA2440-20gc
    };

    //! Valid values for UserDefinedValueSelector
    enum UserDefinedValueSelectorEnums
    {
        UserDefinedValueSelector_Value1,  //!< The user-defined value 1 can be configured - Applies to: acA2440-20gc
        UserDefinedValueSelector_Value2,  //!< The user-defined value 2 can be configured - Applies to: acA2440-20gc
        UserDefinedValueSelector_Value3,  //!< The user-defined value 3 can be configured - Applies to: acA2440-20gc
        UserDefinedValueSelector_Value4,  //!< The user-defined value 4 can be configured - Applies to: acA2440-20gc
        UserDefinedValueSelector_Value5  //!< The user-defined value 5 can be configured - Applies to: acA2440-20gc
    };

    //! Valid values for UserOutputSelector
    enum UserOutputSelectorEnums
    {
        UserOutputSelector_UserOutput1,  //!< The user-settable output signal 1 can be configured - Applies to: acA2440-20gc
        UserOutputSelector_UserOutput2  //!< The user-settable output signal 2 can be configured - Applies to: acA2440-20gc
    };

    //! Valid values for UserSetDefaultSelector
    enum UserSetDefaultSelectorEnums
    {
        UserSetDefaultSelector_AutoFunctions,  //!< The Auto Functions factory set is set as the default startup set - Applies to: acA2440-20gc
        UserSetDefaultSelector_ColorRaw,  //!< The Color Raw factory set is set as the default startup set - Applies to: acA2440-20gc
        UserSetDefaultSelector_Default,  //!< The Default User Set factory set is set as the default startup set - Applies to: acA2440-20gc
        UserSetDefaultSelector_HighGain,  //!< The High Gain factory set is set as the default startup set - Applies to: acA2440-20gc
        UserSetDefaultSelector_UserSet1,  //!< User set 1 is set as the default startup set - Applies to: acA2440-20gc
        UserSetDefaultSelector_UserSet2,  //!< User set 2 is set as the default startup set - Applies to: acA2440-20gc
        UserSetDefaultSelector_UserSet3  //!< User set 3 is set as the default startup set - Applies to: acA2440-20gc
    };

    //! Valid values for UserSetSelector
    enum UserSetSelectorEnums
    {
        UserSetSelector_AutoFunctions,  //!< The Auto Functions factory set can be loaded - Applies to: acA2440-20gc
        UserSetSelector_ColorRaw,  //!< The Color Raw factory set can be loaded - Applies to: acA2440-20gc
        UserSetSelector_Default,  //!< The Default User Set factory set can be loaded - Applies to: acA2440-20gc
        UserSetSelector_HighGain,  //!< The High Gain factory set can be loaded - Applies to: acA2440-20gc
        UserSetSelector_UserSet1,  //!< User set 1 can be saved, loaded, or configured - Applies to: acA2440-20gc
        UserSetSelector_UserSet2,  //!< User set 2 can be saved, loaded, or configured - Applies to: acA2440-20gc
        UserSetSelector_UserSet3  //!< User set 3 can be saved, loaded, or configured - Applies to: acA2440-20gc
    };

    //! Valid values for VignettingCorrectionMode
    enum VignettingCorrectionModeEnums
    {
        VignettingCorrectionMode_Todo  //!< TODO - Applies to: acA2440-20gc
    };


    
    
    //**************************************************************************************************
    // Parameter class BaslerCameraCameraParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for acA2440-20gc

    Sources:
    acA2440-20gc 107213-21;U;acA2440_20g;V2.1-0;1
    */
    class BaslerCameraCameraParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            BaslerCameraCameraParams(void);

            //! Destructor
            ~BaslerCameraCameraParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class BaslerCameraCameraParams_Data;
        BaslerCameraCameraParams_Data* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Number of frames to acquire for each Acquisition Start trigger - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionFrameCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionFrameCount;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Acquisition frame rate of the camera in frames per second - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionFrameRateAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AcquisitionFrameRateAbs;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Enables setting the camera's acquisition frame rate to a specified value - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionFrameRateEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AcquisitionFrameRateEnable;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Sets the image acquisition mode - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selecting Parameters: AcquisitionStart and AcquisitionStop

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AcquisitionModeEnums>& AcquisitionMode;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Starts the acquisition of images - Applies to: acA2440-20gc

        Starts the acquisition of images. If the camera is configured for single frame acquisition, it will start the acquisition of one frame. If the camera is configured for continuous frame acquisition, it will start the continuous acquisition of frames.
    
        Visibility: Beginner

        Selected by: AcquisitionMode

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& AcquisitionStart;

    //@}


    //! \name Categories: AcquisitionStartEventData
    //@{
    /*!
        \brief Stream channel index of the Acquisition Start event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStartEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionStartEventStreamChannelIndex;

    //@}


    //! \name Categories: AcquisitionStartEventData
    //@{
    /*!
        \brief Timestamp of the Acquisition Start event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStartEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionStartEventTimestamp;

    //@}


    //! \name Categories: AcquisitionStartOvertriggerEventData
    //@{
    /*!
        \brief Stream channel index of the Acquisition Start Overtrigger event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStartOvertriggerEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionStartOvertriggerEventStreamChannelIndex;

    //@}


    //! \name Categories: AcquisitionStartOvertriggerEventData
    //@{
    /*!
        \brief Timestamp of the Acquisition Start Overtrigger event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStartOvertriggerEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionStartOvertriggerEventTimestamp;

    //@}


    //! \name Categories: AcquisitionStartWaitEventData
    //@{
    /*!
        \brief Stream channel index of the Acquisition Start Wait event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStartWaitEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionStartWaitEventStreamChannelIndex;

    //@}


    //! \name Categories: AcquisitionStartWaitEventData
    //@{
    /*!
        \brief Timestamp of the Acquisition Start Wait event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStartWaitEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionStartWaitEventTimestamp;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Indicates whether the camera is waiting for trigger signals - Applies to: acA2440-20gc

        Indicates whether the camera is waiting for trigger signals. You should only use this feature if the camera is configured for software triggering. If the camera is configured for hardware triggering, monitor the camera's Trigger Wait signals instead.
    
        Visibility: Expert

        Selected by: AcquisitionStatusSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AcquisitionStatus;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Sets the signal whose status you want to check - Applies to: acA2440-20gc

        Sets the signal whose status you want to check. Its status can be checked by reading the Acquisition Status parameter value.
    
        Visibility: Expert

        Selecting Parameters: AcquisitionStatus

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStatusSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AcquisitionStatusSelectorEnums>& AcquisitionStatusSelector;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Stops the acquisition of images - Applies to: acA2440-20gc

        Stops the acquisition of images if a continuous image acquisition is in progress.
    
        Visibility: Beginner

        Selected by: AcquisitionMode

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStop" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& AcquisitionStop;

    //@}


    //! \name Categories: ActionControl
    //@{
    /*!
        \brief Device key used for action commands - Applies to: acA2440-20gc

        Device key used to authorize the execution of an action command. If the action device key in the camera and the action device key in the protocol message are identical, the camera will execute the corresponding action.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ActionDeviceKey" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ActionDeviceKey;

    //@}


    //! \name Categories: ActionControl
    //@{
    /*!
        \brief Group key used for action commands - Applies to: acA2440-20gc

        Group key used to define a group of cameras on which action commands can be executed.
    
        Visibility: Guru

        Selected by: ActionSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ActionGroupKey" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ActionGroupKey;

    //@}


    //! \name Categories: ActionControl
    //@{
    /*!
        \brief Group mask used for action commands - Applies to: acA2440-20gc

        Group mask used to filter out a sub-group of cameras belonging to a group of cameras. The cameras belonging to a sub-group execute an action at the same time. The filtering is done using a logical bitwise AND operation on the group mask number of the action command and the group mask number of a camera. If both binary numbers have at least one common bit set to 1 (i.e., the result of the AND operation is non-zero), the corresponding camera belongs to the sub-group.
    
        Visibility: Guru

        Selected by: ActionSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ActionGroupMask" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ActionGroupMask;

    //@}


    //! \name Categories: ActionLateEventData
    //@{
    /*!
        \brief Stream channel index of the Action Late event - Applies to: acA2440-20gc

        Stream channel index of the Action Late event. An Action Late event is raised when a scheduled action command with a timestamp in the past is received.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ActionLateEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ActionLateEventStreamChannelIndex;

    //@}


    //! \name Categories: ActionLateEventData
    //@{
    /*!
        \brief Timestamp of the Action Late event - Applies to: acA2440-20gc

        Timestamp of the Action Late event. An Action Late event is raised when a scheduled action command with a timestamp in the past is received.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ActionLateEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ActionLateEventTimestamp;

    //@}


    //! \name Categories: ActionControl
    //@{
    /*!
        \brief Action command to be configured - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selecting Parameters: ActionGroupKey and ActionGroupMask

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ActionSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ActionSelector;

    //@}


    //! \name Categories: AutoFunctions
    //@{
    /*!
        \brief Lower limit of the Exposure Time parameter when the Exposure Auto auto function is active - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoExposureTimeAbsLowerLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoExposureTimeAbsLowerLimit;

    //@}


    //! \name Categories: AutoFunctions
    //@{
    /*!
        \brief Upper limit of the Exposure Time parameter when the Exposure Auto auto function is active - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoExposureTimeAbsUpperLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoExposureTimeAbsUpperLimit;

    //@}


    //! \name Categories: AutoFunctions
    //@{
    /*!
        \brief Lower limit of the Exposure Time parameter when the Exposure Auto auto function is active (raw value) - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoExposureTimeLowerLimitRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoExposureTimeLowerLimitRaw;

    //@}


    //! \name Categories: AutoFunctions
    //@{
    /*!
        \brief Upper limit of the Exposure Time parameter when the Exposure Auto auto function is active (raw value) - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoExposureTimeUpperLimitRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoExposureTimeUpperLimitRaw;

    //@}


    //! \name Categories: AutoFunctionAOIs
    //@{
    /*!
        \brief Height of the auto function AOI (in pixels) - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: AutoFunctionAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOIHeight" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionAOIHeight;

    //@}


    //! \name Categories: AutoFunctionAOIs
    //@{
    /*!
        \brief Horizontal offset of the auto function AOI from the left side of the sensor (in pixels) - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: AutoFunctionAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOIOffsetX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionAOIOffsetX;

    //@}


    //! \name Categories: AutoFunctionAOIs
    //@{
    /*!
        \brief Vertical offset from the top of the sensor to the auto function AOI (in pixels) - Applies to: acA2440-20gc

        Vertical offset of the auto function AOI from the top of the sensor (in pixels).
    
        Visibility: Beginner

        Selected by: AutoFunctionAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOIOffsetY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionAOIOffsetY;

    //@}


    //! \name Categories: AutoFunctionAOIs
    //@{
    /*!
        \brief Sets which auto function AOI can be configured - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selecting Parameters: AutoFunctionAOIWidth, AutoFunctionAOIHeight, AutoFunctionAOIOffsetX, AutoFunctionAOIOffsetY, AutoFunctionAOIUsageIntensity and AutoFunctionAOIUsageWhiteBalance

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOISelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AutoFunctionAOISelectorEnums>& AutoFunctionAOISelector;

    //@}


    //! \name Categories: AutoFunctionAOIs
    //@{
    /*!
        \brief Assigns the Gain Auto and the Exposure Auto auto functions to the currently selected auto function AOI - Applies to: acA2440-20gc

        Assigns the Gain Auto and the Exposure Auto auto functions to the currently selected auto function AOI. For this parameter, Gain Auto and Exposure Auto are considered as a single auto function named 'Intensity'.
    
        Visibility: Beginner

        Selected by: AutoFunctionAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOIUsageIntensity" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AutoFunctionAOIUsageIntensity;

    //@}


    //! \name Categories: AutoFunctionAOIs
    //@{
    /*!
        \brief Assigns the Balance White Auto auto function to the currently selected auto function AOI - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: AutoFunctionAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOIUsageWhiteBalance" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AutoFunctionAOIUsageWhiteBalance;

    //@}


    //! \name Categories: AutoFunctionAOIs
    //@{
    /*!
        \brief Width of the auto function AOI (in pixels) - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: AutoFunctionAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOIWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionAOIWidth;

    //@}


    //! \name Categories: AutoFunctions
    //@{
    /*!
        \brief Sets how gain and exposure time will be balanced when the camera is making automatic adjustments - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionProfile" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AutoFunctionProfileEnums>& AutoFunctionProfile;

    //@}


    //! \name Categories: AutoFunctions
    //@{
    /*!
        \brief Lower limit of the Gain parameter when the Gain Auto auto function is active (raw value) - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoGainRawLowerLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoGainRawLowerLimit;

    //@}


    //! \name Categories: AutoFunctions
    //@{
    /*!
        \brief Upper limit of the Gain parameter when the Gain Auto auto function is active (raw value) - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoGainRawUpperLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoGainRawUpperLimit;

    //@}


    //! \name Categories: AutoFunctions
    //@{
    /*!
        \brief Target brightness for the Gain Auto and the Exposure Auto auto functions - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoTargetValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoTargetValue;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief A serial framing error occurred on reception - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialFramingError" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& BLCSerialFramingError;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief A serial parity error occurred on reception - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialParityError" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& BLCSerialParityError;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Reports the baud rate of the serial communication module - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortBaudRate" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BLCSerialPortBaudRateEnums>& BLCSerialPortBaudRate;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Clears the error flags of the serial communication module - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortClearErrors" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& BLCSerialPortClearErrors;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Reports the parity bit configuration of the serial communication module - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortParity" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BLCSerialPortParityEnums>& BLCSerialPortParity;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Reads and removes the front byte value from the serial communication receive queue - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortReceiveCmd" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& BLCSerialPortReceiveCmd;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Last byte value read from the serial communication receive queue - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortReceiveValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BLCSerialPortReceiveValue;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Sets the signal source for the serial communication module - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BLCSerialPortSourceEnums>& BLCSerialPortSource;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Reports the number of stop bits used by the serial communication module - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortStopBits" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BLCSerialPortStopBitsEnums>& BLCSerialPortStopBits;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Writes the current byte value to the transmit queue - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortTransmitCmd" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& BLCSerialPortTransmitCmd;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Byte value to be written to the transmit queue - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortTransmitValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BLCSerialPortTransmitValue;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Reports the status of the serial communication receive queue - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialReceiveQueueStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BLCSerialReceiveQueueStatusEnums>& BLCSerialReceiveQueueStatus;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Reports the status of the serial communication transmit queue - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialTransmitQueueStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BLCSerialTransmitQueueStatusEnums>& BLCSerialTransmitQueueStatus;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Balance Ratio value to be applied to the currently selected channel - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: BalanceRatioSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceRatioAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BalanceRatioAbs;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Balance Ratio value to be applied to the currently selected channel (raw value) - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: BalanceRatioSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceRatioRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BalanceRatioRaw;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets which color channel can be adjusted when performing manual white balance - Applies to: acA2440-20gc

        Sets which color channel can be adjusted when performing manual white balance. All changes to the Balance Ratio parameter will be applied to the selected color channel.
    
        Visibility: Beginner

        Selecting Parameters: BalanceRatioAbs and BalanceRatioRaw

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceRatioSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BalanceRatioSelectorEnums>& BalanceRatioSelector;

    //@}


    //! \name Categories: AutoFunctions
    //@{
    /*!
        \brief Balance White adjustment damping factor to be applied - Applies to: acA2440-20gc

        Balance White adjustment damping factor to be applied. This controls the speed with which the camera adjusts colors when the Balance White Auto auto function is enabled. This can be useful, for example, when objects move into the camera's field of view and the light conditions are changing gradually due to the moving objects.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceWhiteAdjustmentDampingAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BalanceWhiteAdjustmentDampingAbs;

    //@}


    //! \name Categories: AutoFunctions
    //@{
    /*!
        \brief Balance White adjustment damping factor to be applied (raw value) - Applies to: acA2440-20gc

        Balance White adjustment damping factor to be applied (raw value). This controls the speed with which the camera adjusts colors when the Balance White Auto auto function is enabled. This can be useful, for example, when objects move into the camera's field of view and the light conditions are changing gradually due to the moving objects.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceWhiteAdjustmentDampingRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BalanceWhiteAdjustmentDampingRaw;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets the operation mode of the Balance White Auto auto function - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceWhiteAuto" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BalanceWhiteAutoEnums>& BalanceWhiteAuto;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Resets all white balance adjustments - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceWhiteReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& BalanceWhiteReset;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Number of adjacent horizontal pixels to be summed - Applies to: acA2440-20gc

        Number of adjacent horizontal pixels to be summed. Their charges will be summed and reported out of the camera as a single pixel.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningHorizontal" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BinningHorizontal;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Sets the binning mode for horizontal binning - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningHorizontalMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BinningHorizontalModeEnums>& BinningHorizontalMode;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Number of adjacent vertical pixels to be summed - Applies to: acA2440-20gc

        Number of adjacent vertical pixels to be summed. Their charges will be summed and reported out of the camera as a single pixel.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningVertical" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BinningVertical;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Sets the binning mode for vertical binning - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningVerticalMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BinningVerticalModeEnums>& BinningVerticalMode;

    //@}


    //! \name Categories: AnalogControls
    //@{
    /*!
        \brief Black level value to be applied to the currently selected sensor tap (raw value) - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: BlackLevelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BlackLevelRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BlackLevelRaw;

    //@}


    //! \name Categories: AnalogControls
    //@{
    /*!
        \brief Sets which sensor tap can be configured - Applies to: acA2440-20gc

        Sets which sensor tap can be configured. All changes to the Black Level parameter will be applied to the selected sensor tap.
    
        Visibility: Beginner

        Selecting Parameters: BlackLevelRaw

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BlackLevelSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BlackLevelSelectorEnums>& BlackLevelSelector;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Brightness value to be applied - Applies to: acA2440-20gc

        Adjusting the brightness lightens or darkens the entire image.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslBrightness" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslBrightness;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Brightness value to be applied (raw value) - Applies to: acA2440-20gc

        Adjusting the brightness lightens or darkens the entire image.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslBrightnessRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslBrightnessRaw;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Contrast value to be applied - Applies to: acA2440-20gc

        Adjusting the contrast increases the difference between light and dark areas in the image.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslContrast" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslContrast;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets the contrast mode - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslContrastMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslContrastModeEnums>& BslContrastMode;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Contrast value to be applied (raw value) - Applies to: acA2440-20gc

        Adjusting the contrast increases the difference between light and dark areas in the image.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslContrastRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslContrastRaw;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Hue shift value to be applied - Applies to: acA2440-20gc

        Adjusting the hue shifts the colors of the image. This can be useful, e.g., to correct minor color shifts or to create false-color images.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslHue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslHue;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Hue shift value to be applied (raw value) - Applies to: acA2440-20gc

        Adjusting the hue shifts the colors of the image. This can be useful, e.g., to correct minor color shifts or to create false-color images.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslHueRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslHueRaw;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Searches for light devices connected to your camera - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightControlEnumerateDevices" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& BslLightControlEnumerateDevices;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Indicates whether any of the light devices are currently experiencing problems - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightControlErrorStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightControlErrorStatusEnums>& BslLightControlErrorStatus;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Enables/disables the light control features - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightControlMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightControlModeEnums>& BslLightControlMode;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Sets which line is used to control the light features - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightControlSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightControlSourceEnums>& BslLightControlSource;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Indicates the current state of the control mode - Applies to: acA2440-20gc

        Indicates the current state of the light control mode.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightControlStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightControlStatusEnums>& BslLightControlStatus;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Sets which signal is used to trigger the light in strobe mode - Applies to: acA2440-20gc

        Sets which signal is used to trigger the light in strobe mode. The default setting is Exposure Active.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightControlTriggerMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightControlTriggerModeEnums>& BslLightControlTriggerMode;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Brightness of the light in percent of total brightness available - Applies to: acA2440-20gc

        Brightness of the light in percent of total brightness available. Setting this parameter to 100 % means that the light device draws the maximum current as specified by the the Light Device Max Current parameter.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceBrightness" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslLightDeviceBrightness;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Brightness of the light in percent of total brightness available (raw value) - Applies to: acA2440-20gc

        Brightness of the light in percent of total brightness available (raw value). Setting this parameter to 100 % means that the light device draws the maximum current as specified by the the Light Device Max Current parameter.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceBrightnessRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslLightDeviceBrightnessRaw;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Changes the ID of the currently selected light device - Applies to: acA2440-20gc

        Changes the ID of the currently selected light device. The new ID will be assigned immediately.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceChangeID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightDeviceChangeIDEnums>& BslLightDeviceChangeID;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Clears the last light device error - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceClearLastError" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& BslLightDeviceClearLastError;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Sets how the light device is controlled - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceControlMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightDeviceControlModeEnums>& BslLightDeviceControlMode;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Version of the light device's firmware   - Applies to: acA2440-20gc

        Version of the light device's firmware.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceFirmwareVersion" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& BslLightDeviceFirmwareVersion;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Indicates the last light device error - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceLastError" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightDeviceLastErrorEnums>& BslLightDeviceLastError;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Maximum current that the light device is going to use - Applies to: acA2440-20gc

        Maximum current that the light device is going to use. The value should not exceed the power rating of the device. To change the setting, the Light Device Operation Mode parameter must be set to Off.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceMaxCurrent" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslLightDeviceMaxCurrent;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Maximum current that the light device is going to use (raw value) - Applies to: acA2440-20gc

        Maximum current that the light device is going to use (raw value). The value should not exceed the power rating of the device. To change the setting, the Light Device Operation Mode parameter must be set to Off.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceMaxCurrentRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslLightDeviceMaxCurrentRaw;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Name of the light device model - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceModelName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& BslLightDeviceModelName;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Sets the operation mode of the light device - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceOperationMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightDeviceOperationModeEnums>& BslLightDeviceOperationMode;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Maximum current to be used when operating the light device in overdrive - Applies to: acA2440-20gc

        Maximum current to be used when operating the light device in overdrive. This parameter value is relative to the value of the Light Device Max Current parameter.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceOverdriveLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslLightDeviceOverdriveLimit;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Maximum current to be used when operating the light device in overdrive (raw value) - Applies to: acA2440-20gc

        Maximum current to be used when operating the light device in overdrive (raw value). This parameter value is relative to the value of the Light Device Max Current parameter.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceOverdriveLimitRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslLightDeviceOverdriveLimitRaw;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Sets which light device can be configured - Applies to: acA2440-20gc

        Sets which light device can be configured. To populate the list, use the Light Control Enumerate Devices command first. All subsequent parameter changes in this category will be applied to the device selected here.
    
        Visibility: Expert

        Selecting Parameters: BslLightDeviceControlMode, BslLightDeviceMaxCurrent, BslLightDeviceMaxCurrentRaw, BslLightDeviceBrightness, BslLightDeviceBrightnessRaw, BslLightDeviceOperationMode, BslLightDeviceStrobeMode, BslLightDeviceStrobeDuration, BslLightDeviceStrobeDurationRaw, BslLightDeviceOverdriveLimit, BslLightDeviceOverdriveLimitRaw, BslLightDeviceLastError, BslLightDeviceClearLastError, BslLightDeviceChangeID, BslLightDeviceModelName and BslLightDeviceFirmwareVersion

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightDeviceSelectorEnums>& BslLightDeviceSelector;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Duration of the individual strobe pulses - Applies to: acA2440-20gc

        Duration of the individual strobe pulses. The maximum value is 655 350 microseconds.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceStrobeDuration" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslLightDeviceStrobeDuration;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Duration of the individual strobe pulses (raw value) - Applies to: acA2440-20gc

        Duration of the individual strobe pulses (raw value). The maximum value is 655 350 microseconds.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceStrobeDurationRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslLightDeviceStrobeDurationRaw;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Sets the strobe mode of the light device - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceStrobeMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightDeviceStrobeModeEnums>& BslLightDeviceStrobeMode;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Saturation value to be applied - Applies to: acA2440-20gc

        Adjusting the saturation changes the colorfulness (intensity) of the colors. A higher saturation, for example, makes colors easier to distinguish.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslSaturation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslSaturation;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Saturation value to be applied (raw value) - Applies to: acA2440-20gc

        Adjusting the saturation changes the colorfulness (intensity) of the colors. A higher saturation, for example, makes colors easier to distinguish.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslSaturationRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslSaturationRaw;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Centers the image horizontally - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CenterX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& CenterX;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Centers the image vertically - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CenterY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& CenterY;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Maximum possible pixel value in the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkDynamicRangeMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkDynamicRangeMax;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Minimum possible pixel value in the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkDynamicRangeMin" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkDynamicRangeMin;

    //@}


    //! \name Categories: ChunkDataStreams
    //@{
    /*!
        \brief Includes the currently selected chunk in the payload data - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: ChunkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ChunkEnable;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Exposure time used to acquire the image - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkExposureTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ChunkExposureTime;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Frame Trigger counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkFrameTriggerCounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkFrameTriggerCounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Frame Trigger Ignored counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkFrameTriggerIgnoredCounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkFrameTriggerIgnoredCounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Frame counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkFramecounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkFramecounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Frames per Trigger counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkFramesPerTriggerCounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkFramesPerTriggerCounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Gain All value of the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkGainAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkGainAll;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief AOI height of the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkHeight" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkHeight;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Number of bits per line used for the Input Status At Line Trigger parameter - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkInputStatusAtLineTriggerBitsPerLine" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkInputStatusAtLineTriggerBitsPerLine;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Index number used for the Input Status At Line Trigger parameter - Applies to: acA2440-20gc

        Index number used for the Input Status At Line Trigger parameter. The index number can be used to get the state of the camera's input lines when a specific line was acquired. For example, if you want to know the state of the camera's input lines when line 30 was acquired, set the index to 30, then retrieve the value of Status Index parameter.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkInputStatusAtLineTriggerIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkInputStatusAtLineTriggerIndex;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value indicating the status of the camera's input lines when a specific line was acquired - Applies to: acA2440-20gc

        Value indicating the status of the camera's input lines when a specific line was acquired. The information is stored in a 4-bit value (bit 0 = input line 1 state, bit 1 = input line 2 state etc.). For more information, see the Status Index parameter documentation.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkInputStatusAtLineTriggerValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkInputStatusAtLineTriggerValue;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Bit field that indicates the status of all of the camera's input and output lines when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkLineStatusAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkLineStatusAll;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Line Trigger counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkLineTriggerCounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkLineTriggerCounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Line Trigger End to End counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkLineTriggerEndToEndCounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkLineTriggerEndToEndCounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Line Trigger Ignored counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkLineTriggerIgnoredCounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkLineTriggerIgnoredCounter;

    //@}


    //! \name Categories: ChunkDataStreams
    //@{
    /*!
        \brief Enables the chunk mode - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkModeActive" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ChunkModeActive;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief X offset of the AOI of the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkOffsetX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkOffsetX;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Y offset of the AOI of the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkOffsetY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkOffsetY;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief CRC checksum of the acquired image - Applies to: acA2440-20gc

        CRC checksum of the acquired image. The checksum is calculated using all of the image data and all of the appended chunks except for the checksum itself.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkPayloadCRC16" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkPayloadCRC16;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Indicates the pixel format of the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkPixelFormat" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ChunkPixelFormatEnums>& ChunkPixelFormat;

    //@}


    //! \name Categories: ChunkDataStreams
    //@{
    /*!
        \brief Sets which chunk can be enabled - Applies to: acA2440-20gc

        Sets which chunk can be enabled. The chunk can be enabled using the Chunk Enable parameter.
    
        Visibility: Beginner

        Selecting Parameters: ChunkEnable

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ChunkSelectorEnums>& ChunkSelector;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Sequence set index number related to the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkSequenceSetIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkSequenceSetIndex;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Shaft Encoder counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkShaftEncoderCounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkShaftEncoderCounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Number of bytes of data between the beginning of one line in the acquired image and the beginning of the next line in the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkStride" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkStride;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the timestamp when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkTimestamp;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Trigger Input counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkTriggerinputcounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkTriggerinputcounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Status of all of the camera's virtual input and output lines when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkVirtLineStatusAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkVirtLineStatusAll;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Width of the AOI of the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkWidth;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Clears the last error - Applies to: acA2440-20gc

        Clears the last error. If a previous error exists, the previous error can still be retrieved.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ClearLastError" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& ClearLastError;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Enables color adjustment - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ColorAdjustmentEnable;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Hue adjustment value to be applied to the currently selected color channel - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: ColorAdjustmentSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentHue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ColorAdjustmentHue;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Hue adjustment value to be applied to the currently selected color channel (raw value) - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: ColorAdjustmentSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentHueRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ColorAdjustmentHueRaw;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Allows you to restore previous color adjustment settings - Applies to: acA2440-20gc

        Allows you to restore the color adjustment settings that were in force before the settings were last changed.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& ColorAdjustmentReset;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Saturation adjustment value to be applied to the currently selected color channel - Applies to: acA2440-20gc

        Saturation adjustment value  to be applied to the currently selected color channel.
    
        Visibility: Expert

        Selected by: ColorAdjustmentSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentSaturation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ColorAdjustmentSaturation;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Saturation adjustment value to be applied to the currently selected color channel (raw value) - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: ColorAdjustmentSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentSaturationRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ColorAdjustmentSaturationRaw;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets which color in your images will be adjusted - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selecting Parameters: ColorAdjustmentHue, ColorAdjustmentHueRaw, ColorAdjustmentSaturation and ColorAdjustmentSaturationRaw

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorAdjustmentSelectorEnums>& ColorAdjustmentSelector;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Extent to which the color matrix influences the color values - Applies to: acA2440-20gc

        Extent to which the color matrix influences the color values. If set to 0, the matrix is effectively disabled.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationMatrixFactor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ColorTransformationMatrixFactor;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Extent to which the color matrix influences the color values (raw value) - Applies to: acA2440-20gc

        Extent to which the color matrix influences the color values (raw value). If set to 0, the matrix is effectively disabled.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationMatrixFactorRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ColorTransformationMatrixFactorRaw;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets which type of color transformation will be performed - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selecting Parameters: LightSourceSelector, ColorTransformationValueSelector and ColorTransformationValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorTransformationSelectorEnums>& ColorTransformationSelector;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Transformation value for the selected element in the color transformation matrix - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: ColorTransformationSelector and ColorTransformationValueSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ColorTransformationValue;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Transformation value for the selected element in the color transformation matrix (raw value) - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: ColorTransformationValueSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationValueRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ColorTransformationValueRaw;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets which element will be entered in the color transformation matrix - Applies to: acA2440-20gc

        Sets which element will be entered in the color transformation matrix. Depending on the camera model, some elements in the color transformation matrix may be preset and can't be changed.
    
        Visibility: Guru

        Selected by: ColorTransformationSelector

        Selecting Parameters: ColorTransformationValue and ColorTransformationValueRaw

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationValueSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorTransformationValueSelectorEnums>& ColorTransformationValueSelector;

    //@}


    //! \name Categories: TimerControls
    //@{
    /*!
        \brief Sets which event that increases the currently selected counter - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterEventSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<CounterEventSourceEnums>& CounterEventSource;

    //@}


    //! \name Categories: TimerControls
    //@{
    /*!
        \brief Immediately resets the selected counter - Applies to: acA2440-20gc

        Immediately resets the selected counter. The counter starts counting again immediately after the reset.
    
        Visibility: Expert

        Selected by: CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& CounterReset;

    //@}


    //! \name Categories: TimerControls
    //@{
    /*!
        \brief Sets which source signal will reset the currently selected counter - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterResetSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<CounterResetSourceEnums>& CounterResetSource;

    //@}


    //! \name Categories: TimerControls
    //@{
    /*!
        \brief Sets which counter can be configured - Applies to: acA2440-20gc

        Sets which counter can be configured. All changes to the counter settings will be applied to the selected counter.
    
        Visibility: Expert

        Selecting Parameters: CounterEventSource, CounterReset and CounterResetSource

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<CounterSelectorEnums>& CounterSelector;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Indicates whether the critical temperature has been reached - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CriticalTemperature" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& CriticalTemperature;

    //@}


    //! \name Categories: CriticalTemperatureEventData
    //@{
    /*!
        \brief Stream channel index of the Critical Temperature event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CriticalTemperatureEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& CriticalTemperatureEventStreamChannelIndex;

    //@}


    //! \name Categories: CriticalTemperatureEventData
    //@{
    /*!
        \brief Timestamp of the Critical Temperature event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CriticalTemperatureEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& CriticalTemperatureEventTimestamp;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Horizontal decimation factor - Applies to: acA2440-20gc

        Horizontal decimation factor. This specifies the extent of horizontal sub-sampling of the acquired frame, i.e., it defines how many pixel columns are left out of transmission. This has the net effect of reducing the horizontal resolution (width) of the image by the specified decimation factor. A value of 1 means that the camera performs no horizontal decimation.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DecimationHorizontal" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DecimationHorizontal;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Vertical decimation factor - Applies to: acA2440-20gc

        Vertical decimation factor. This specifies the extent of vertical sub-sampling of the acquired frame, i.e., it defines how many rows are left out of transmission. This has the net effect of reducing the vertical resolution (height) of the image by the specified decimation factor. A value of 1 means that the camera performs no vertical decimation.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DecimationVertical" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DecimationVertical;

    //@}


    //! \name Categories: PGIControl
    //@{
    /*!
        \brief Sets the demosaicing mode - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DemosaicingMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DemosaicingModeEnums>& DemosaicingMode;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Version of the camera's firmware - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceFirmwareVersion" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceFirmwareVersion;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief ID of the camera - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceID;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Additional information from the vendor about the camera - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceManufacturerInfo" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceManufacturerInfo;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Model name of the camera - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceModelName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceModelName;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Announces the end of feature streaming - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceRegistersStreamingEnd" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& DeviceRegistersStreamingEnd;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Prepares the camera for feature streaming - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceRegistersStreamingStart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& DeviceRegistersStreamingStart;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Immediately resets and restarts the camera - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& DeviceReset;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Major version number of the SFNC specification that the camera is compatible with - Applies to: acA2440-20gc

        Major version number of the Standard Features Naming Convention (SFNC) specification that the camera is compatible with.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSFNCVersionMajor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceSFNCVersionMajor;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Minor version number of the SFNC specification that the camera is compatible with - Applies to: acA2440-20gc

        Minor version number of the Standard Features Naming Convention (SFNC) specification that the camera is compatible with.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSFNCVersionMinor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceSFNCVersionMinor;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Subminor version number of the SFNC specification that the camera is compatible with - Applies to: acA2440-20gc

        Subminor version number of the Standard Features Naming Convention (SFNC) specification that the camera is compatible with.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSFNCVersionSubMinor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceSFNCVersionSubMinor;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Indicates the scan type of the camera's sensor (area or line scan) - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceScanType" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceScanTypeEnums>& DeviceScanType;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief User-settable ID of the camera - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceUserID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceUserID;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Name of the camera vendor - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceVendorName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceVendorName;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Version of the camera - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceVersion" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceVersion;

    //@}


    //! \name Categories: AnalogControls
    //@{
    /*!
        \brief Digital shift to be applied - Applies to: acA2440-20gc

        Digital shift allows you to multiply the pixel values in an image. This increases the brightness of the image. If the parameter is set to zero, digital shift is disabled.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DigitalShift" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DigitalShift;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Enables Burst Acquisition - Applies to: acA2440-20gc

        Enables Burst Acquisition. If enabled, the maximum frame rate only depends on the sensor timing and the timing of the trigger sequence. The image transfer rate out of the camera has no influence on the frame rate.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EnableBurstAcquisition" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& EnableBurstAcquisition;

    //@}


    //! \name Categories: EventsGeneration
    //@{
    /*!
        \brief Enables event notifications for the currently selected event - Applies to: acA2440-20gc

        Enables event notifications for the currently selected event. The event can selected using the Event Selector parameter.
    
        Visibility: Beginner

        Selected by: EventSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventNotification" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<EventNotificationEnums>& EventNotification;

    //@}


    //! \name Categories: EventOverrunEventData
    //@{
    /*!
        \brief Frame ID of the Event Overrun event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventOverrunEventFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventOverrunEventFrameID;

    //@}


    //! \name Categories: EventOverrunEventData
    //@{
    /*!
        \brief Stream channel index of the Event Overrun event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventOverrunEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventOverrunEventStreamChannelIndex;

    //@}


    //! \name Categories: EventOverrunEventData
    //@{
    /*!
        \brief Timestamp of the Event Overrun event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventOverrunEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventOverrunEventTimestamp;

    //@}


    //! \name Categories: EventsGeneration
    //@{
    /*!
        \brief Sets the event notification to be enabled - Applies to: acA2440-20gc

        Sets the event notification to be enabled. The notification can be enabled using the Event Notification parameter.
    
        Visibility: Beginner

        Selecting Parameters: EventNotification

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<EventSelectorEnums>& EventSelector;

    //@}


    //! \name Categories: ExpertFeatureAccess
    //@{
    /*!
        \brief Key for making the selected expert feature available - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: ExpertFeatureAccessSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExpertFeatureAccessKey" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ExpertFeatureAccessKey;

    //@}


    //! \name Categories: ExpertFeatureAccess
    //@{
    /*!
        \brief Sets the expert feature to be made available - Applies to: acA2440-20gc

        Sets the expert feature to be made available. All changes will be applied to the selected feature.
    
        Visibility: Guru

        Selecting Parameters: ExpertFeatureEnable and ExpertFeatureAccessKey

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExpertFeatureAccessSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExpertFeatureAccessSelectorEnums>& ExpertFeatureAccessSelector;

    //@}


    //! \name Categories: ExpertFeatureAccess
    //@{
    /*!
        \brief Enables the currently selected expert feature - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: ExpertFeatureAccessSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExpertFeatureEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ExpertFeatureEnable;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Sets the operation mode of the Exposure Auto auto function - Applies to: acA2440-20gc

        Sets the operation mode of the Exposure Auto auto function. The Exposure Auto auto function automatically adjusts the exposure time within set limits until a target brightness value has been reached.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureAuto" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExposureAutoEnums>& ExposureAuto;

    //@}


    //! \name Categories: ExposureEndEventData
    //@{
    /*!
        \brief Frame ID of the Exposure End event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureEndEventFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ExposureEndEventFrameID;

    //@}


    //! \name Categories: ExposureEndEventData
    //@{
    /*!
        \brief Stream channel index of the Exposure End event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureEndEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ExposureEndEventStreamChannelIndex;

    //@}


    //! \name Categories: ExposureEndEventData
    //@{
    /*!
        \brief Timestamp of the Exposure End event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureEndEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ExposureEndEventTimestamp;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Sets the exposure mode - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExposureModeEnums>& ExposureMode;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Maximum overlap of the sensor exposure with sensor readout in Trigger Width exposure mode (in microseconds) - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureOverlapTimeMaxAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ExposureOverlapTimeMaxAbs;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Maximum overlap of the sensor exposure with sensor readout in Trigger Width exposure mode (raw value) - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureOverlapTimeMaxRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ExposureOverlapTimeMaxRaw;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Sets the exposure overlap time mode - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureOverlapTimeMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExposureOverlapTimeModeEnums>& ExposureOverlapTimeMode;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Exposure time of the camera in microseconds - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureTimeAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ExposureTimeAbs;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Sets the exposure time mode - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureTimeMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExposureTimeModeEnums>& ExposureTimeMode;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Exposure time of the camera (raw value) - Applies to: acA2440-20gc

        Exposure time of the camera (raw value). The actual exposure time equals the current Exposure Time (Raw) value multiplied with the current Exposure Timebase value.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureTimeRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ExposureTimeRaw;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Access buffer for file operations - Applies to: acA2440-20gc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileAccessBuffer" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IRegisterEx& FileAccessBuffer;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Number of bytes read from the file into the file access buffer or written to the file from the file access buffer - Applies to: acA2440-20gc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileAccessLength" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileAccessLength;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Number of bytes after which FileAccessLength bytes are read from the file into the file access buffer or are written to the file from the file access buffer - Applies to: acA2440-20gc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileAccessOffset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileAccessOffset;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Sets the access mode in which a file is opened in the camera - Applies to: acA2440-20gc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOpenMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileOpenModeEnums>& FileOpenMode;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Executes the operation selected by File Operation Selector parameter - Applies to: acA2440-20gc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationExecute" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& FileOperationExecute;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief File operation result - Applies to: acA2440-20gc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationResult" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileOperationResult;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Sets the target operation for the currently selected file - Applies to: acA2440-20gc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector

        Selecting Parameters: FileAccessOffset, FileAccessLength, FileOperationStatus, FileOperationResult and FileOperationExecute

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileOperationSelectorEnums>& FileOperationSelector;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Indicates the file operation execution status - Applies to: acA2440-20gc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileOperationStatusEnums>& FileOperationStatus;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Sets the target file in the camera - Applies to: acA2440-20gc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selecting Parameters: FileOperationSelector, FileOpenMode, FileAccessBuffer, FileAccessOffset, FileAccessLength, FileOperationStatus, FileOperationResult, FileSize and FileOperationExecute

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileSelectorEnums>& FileSelector;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Size of the currently selected file in bytes - Applies to: acA2440-20gc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileSize;

    //@}


    //! \name Categories: FrameStartEventData
    //@{
    /*!
        \brief Stream channel index of the Frame Start event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameStartEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameStartEventStreamChannelIndex;

    //@}


    //! \name Categories: FrameStartEventData
    //@{
    /*!
        \brief Timestamp of the Frame Start event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameStartEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameStartEventTimestamp;

    //@}


    //! \name Categories: FrameStartOvertriggerEventData
    //@{
    /*!
        \brief Stream channel index of the Frame Start Overtrigger event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameStartOvertriggerEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameStartOvertriggerEventStreamChannelIndex;

    //@}


    //! \name Categories: FrameStartOvertriggerEventData
    //@{
    /*!
        \brief Timestamp of the Frame Start Overtrigger event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameStartOvertriggerEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameStartOvertriggerEventTimestamp;

    //@}


    //! \name Categories: FrameStartWaitEventData
    //@{
    /*!
        \brief Stream channel index of the Frame Start Wait event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameStartWaitEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameStartWaitEventStreamChannelIndex;

    //@}


    //! \name Categories: FrameStartWaitEventData
    //@{
    /*!
        \brief Timestamp of the Frame Start Wait event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameStartWaitEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameStartWaitEventTimestamp;

    //@}


    //! \name Categories: FrameTimeoutEventData
    //@{
    /*!
        \brief Stream channel index of the Frame Timeout event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameTimeoutEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameTimeoutEventStreamChannelIndex;

    //@}


    //! \name Categories: FrameTimeoutEventData
    //@{
    /*!
        \brief Timestamp of the Frame Timeout event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameTimeoutEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameTimeoutEventTimestamp;

    //@}


    //! \name Categories: AnalogControls
    //@{
    /*!
        \brief Sets the operation mode of the Gain Auto auto function - Applies to: acA2440-20gc

        Sets the operation mode of the Gain Auto auto function. The Gain Auto auto function automatically adjusts the gain within set limits until a target brightness value has been reached.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GainAuto" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GainAutoEnums>& GainAuto;

    //@}


    //! \name Categories: AnalogControls
    //@{
    /*!
        \brief Value of the currently selected gain (raw value) - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: GainSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GainRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GainRaw;

    //@}


    //! \name Categories: AnalogControls
    //@{
    /*!
        \brief Sets the gain type to be adjusted - Applies to: acA2440-20gc

        Sets the gain type to be adjusted. All changes to the Gain parameter will be applied to the selected gain type.
    
        Visibility: Beginner

        Selecting Parameters: GainRaw

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GainSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GainSelectorEnums>& GainSelector;

    //@}


    //! \name Categories: AnalogControls
    //@{
    /*!
        \brief Gamma correction to be applied - Applies to: acA2440-20gc

        Gamma correction to be applied. Gamma correction allows you to optimize the brightness of acquired images for display on a monitor.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Gamma" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Gamma;

    //@}


    //! \name Categories: AnalogControls
    //@{
    /*!
        \brief Enables gamma correction - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GammaEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GammaEnable;

    //@}


    //! \name Categories: AnalogControls
    //@{
    /*!
        \brief Sets the type of gamma to be applied - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GammaSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GammaSelectorEnums>& GammaSelector;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Sets the control channel privilege - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCCP" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GevCCPEnums>& GevCCP;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Current default gateway of the selected network interface - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCurrentDefaultGateway" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevCurrentDefaultGateway;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Current IP address of the selected network interface - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCurrentIPAddress" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevCurrentIPAddress;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Current IP configuration of the selected network interface - Applies to: acA2440-20gc

        Current IP configuration of the selected network interface, e.g., fixed IP, DHCP, or auto IP.
    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCurrentIPConfiguration" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevCurrentIPConfiguration;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Current subnet mask of the selected network interface - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCurrentSubnetMask" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevCurrentSubnetMask;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Character set used by all strings of the bootstrap registers - Applies to: acA2440-20gc

        Character set used by all strings of the bootstrap registers (1 = UTF8).
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevDeviceModeCharacterSet" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevDeviceModeCharacterSet;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates whether the bootstrap register is in big-endian format - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevDeviceModeIsBigEndian" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevDeviceModeIsBigEndian;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief First URL reference to the GenICam XML file - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevFirstURL" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& GevFirstURL;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Sets the Extended ID mode for GVSP - Applies to: acA2440-20gc

        Sets the Extended ID mode for GVSP (64-bit block ID, 32-bit packet ID). This bit can't be reset if the stream channels do not support the standard ID mode.
    
        Visibility: Expert

        Selected by: GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevGVSPExtendedIDMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GevGVSPExtendedIDModeEnums>& GevGVSPExtendedIDMode;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Heartbeat timeout in milliseconds - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevHeartbeatTimeout" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevHeartbeatTimeout;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Enables the IEEE 1588 V2 Precision Time Protocol for the timestamp register - Applies to: acA2440-20gc

        Enables the IEEE 1588 V2 Precision Time Protocol for the timestamp register. Only available if the IEEE1588_support bit of the GVCP Capability register is set. When PTP is enabled, the Timestamp Control register can't be used to reset the timestamp. When PTP is enabled or disabled, the value of Timestamp Tick Frequency and Timestamp Value registers may change to reflect the new time domain.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevIEEE1588;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Latched IEEE 1588 clock ID of the camera - Applies to: acA2440-20gc

        Latched IEEE 1588 clock ID of the camera. (The clock ID must first be latched using the IEEE 1588 Latch command.) The clock ID is an array of eight octets which is displayed as a hexadecimal number. Leading zeros are omitted.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588ClockId" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevIEEE1588ClockId;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Latches the current IEEE 1588-related values of the camera - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588DataSetLatch" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& GevIEEE1588DataSetLatch;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Latched offset from the IEEE 1588 master clock in nanoseconds - Applies to: acA2440-20gc

        Latched offset from the IEEE 1588 master clock in nanoseconds. (The offset must first be latched using the IEEE 1588 Latch command.)
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588OffsetFromMaster" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevIEEE1588OffsetFromMaster;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Latched IEEE 1588 parent clock ID of the camera - Applies to: acA2440-20gc

        Latched IEEE 1588 parent clock ID of the camera. (The parent clock ID must first be latched using the IEEE 1588 Latch command.) The parent clock ID is the clock ID of the current master clock. A clock ID is an array of eight octets which is displayed as a hexadecimal number. Leading zeros are omitted.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588ParentClockId" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevIEEE1588ParentClockId;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates the state of the IEEE 1588 clock - Applies to: acA2440-20gc

        Indicates the state of the IEEE 1588 clock. Values of this field must match the IEEE 1588 PTP port state enumeration (INITIALIZING, FAULTY, DISABLED, LISTENING, PRE_MASTER, MASTER, PASSIVE, UNCALIBRATED, SLAVE).
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588Status" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GevIEEE1588StatusEnums>& GevIEEE1588Status;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates the latched state of the IEEE 1588 clock - Applies to: acA2440-20gc

        Indicates the latched state of the IEEE 1588 clock. (The state must first be latched using the IEEE 1588 Latch command.) The state is indicated by values 1 to 9, corresponding to the states INITIALIZING, FAULTY, DISABLED, LISTENING, PRE_MASTER, MASTER, PASSIVE, UNCALIBRATED, and SLAVE.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588StatusLatched" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GevIEEE1588StatusLatchedEnums>& GevIEEE1588StatusLatched;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Sets the physical network interface to be configured - Applies to: acA2440-20gc

        Sets the physical network interface to be configured. All changes to the network interface settings will be applied to the selected interface.
    
        Visibility: Guru

        Selecting Parameters: GevMACAddress, GevSupportedOptionalLegacy16BitBlockID, GevSupportedIPConfigurationLLA, GevSupportedIPConfigurationDHCP, GevSupportedIPConfigurationPersistentIP, GevCurrentIPConfiguration, GevCurrentIPAddress, GevCurrentSubnetMask, GevCurrentDefaultGateway, GevPersistentIPAddress, GevPersistentSubnetMask, GevPersistentDefaultGateway, GevLinkSpeed, GevLinkMaster, GevLinkFullDuplex and GevLinkCrossover

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevInterfaceSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GevInterfaceSelectorEnums>& GevInterfaceSelector;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates the state of medium-dependent interface crossover (MDIX) for the selected network interface - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevLinkCrossover" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevLinkCrossover;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates whether the selected network interface operates in full-duplex mode - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevLinkFullDuplex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevLinkFullDuplex;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates whether the selected network interface is the clock master - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevLinkMaster" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevLinkMaster;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Connection speed in Mbps of the selected network interface - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevLinkSpeed" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevLinkSpeed;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief MAC address of the selected network interface - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevMACAddress" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevMACAddress;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Number of message channels supported by the camera - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevMessageChannelCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevMessageChannelCount;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Number of network interfaces of the camera - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevNumberOfInterfaces" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevNumberOfInterfaces;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Fixed default gateway of the selected network interface - Applies to: acA2440-20gc

        Fixed default gateway of the selected network interface (if fixed IP addressing is supported by the camera and enabled).
    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevPersistentDefaultGateway" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevPersistentDefaultGateway;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Fixed IP address of the selected network interface - Applies to: acA2440-20gc

        Fixed IP address of the selected network interface (if fixed IP addressing is supported by the camera and enabled).
    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevPersistentIPAddress" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevPersistentIPAddress;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Fixed subnet mask of the selected network interface - Applies to: acA2440-20gc

        Fixed subnet mask of the selected network interface (if fixed IP addressing is supported by the camera and enabled).
    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevPersistentSubnetMask" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevPersistentSubnetMask;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Base bandwidth in bytes per second that will be used by the camera to transmit image and chunk feature data and to handle resends and control data transmissions - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCBWA" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCBWA;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Percentage of the Ethernet bandwidth assigned to the camera to be held in reserve - Applies to: acA2440-20gc

        Percentage of the Ethernet bandwidth assigned to the camera to be held in reserve for packet resends and for the transmission of control data between the camera and the host computer. The setting is expressed as a percentage of the Bandwidth Assigned parameter. For example, if the Bandwidth Assigned parameter indicates that 30 MBytes/s have been assigned to the camera and the Bandwidth Reserve parameter is set to 5 %, the bandwidth reserve will be 1.5 MBytes/s.
    
        Visibility: Expert

        Selected by: GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCBWR" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCBWR;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Multiplier for the Bandwidth Reserve parameter - Applies to: acA2440-20gc

        Multiplier for the Bandwidth Reserve parameter. The multiplier is used to establish an extra pool of reserved bandwidth that can be used if an unusually large burst of packet resends is needed.
    
        Visibility: Expert

        Selected by: GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCBWRA" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCBWRA;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Destination address of the selected stream channel - Applies to: acA2440-20gc

        Destination address of the selected stream channel. The destination can be a unicast or a multicast address.
    
        Visibility: Guru

        Selected by: GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCDA" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCDA;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Actual bandwidth (in bytes per second) that the camera will use to transmit image data and chunk data - Applies to: acA2440-20gc

        Actual bandwidth (in bytes per second) that the camera will use to transmit image data and chunk data with the current settings for AOI, chunk features, and pixel format.
    
        Visibility: Expert

        Selected by: GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCDCT" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCDCT;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Maximum amount of data (in bytes per second) that the camera can generate - Applies to: acA2440-20gc

        Maximum amount of data (in bytes per second) that the camera can generate with its current settings under ideal conditions, i.e., unlimited bandwidth and no packet resends.
    
        Visibility: Expert

        Selected by: GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCDMT" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCDMT;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Maximum amount of time (in ticks) that the next frame transmission could be delayed due to a burst of resends - Applies to: acA2440-20gc

        Maximum amount of time (in ticks) that the next frame transmission could be delayed due to a burst of resends. If the Bandwidth Reserve Accumulation parameter is set to a high value, the camera can experience periods where there is a large burst of data resends. This burst of resends will delay the start of transmission of the next acquired image.
    
        Visibility: Expert

        Selected by: GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCFJM" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCFJM;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Frame transmission delay on the selected stream channel - Applies to: acA2440-20gc

        Frame transmission delay on the selected stream channel (in ticks). This value sets a delay before transmitting the acquired image.
    
        Visibility: Expert

        Selected by: GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCFTD" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCFTD;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Delay between the transmission of each packet on the selected stream channel - Applies to: acA2440-20gc

        Delay between the transmission of each packet on the selected stream channel. The delay is measured in ticks.
    
        Visibility: Expert

        Selected by: GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCPD" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCPD;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Destination port of the selected stream channel - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCPHostPort" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCPHostPort;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Index of the network interface to be used - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCPInterfaceIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCPInterfaceIndex;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates the endianness of multi-byte pixel data for this stream - Applies to: acA2440-20gc

        Indicates the endianness of multi-byte pixel data for this stream. True equals big-endian.
    
        Visibility: Guru

        Selected by: GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCPSBigEndian" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSCPSBigEndian;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Disables IP fragmentation of packets on the stream channel - Applies to: acA2440-20gc

        Disables IP fragmentation of packets on the stream channel. This bit is copied into the 'do not fragment' bit of the IP header of each stream packet.
    
        Visibility: Guru

        Selected by: GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCPSDoNotFragment" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSCPSDoNotFragment;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Packet size in bytes on the selected stream channel  Excludes data leader and data trailer - Applies to: acA2440-20gc

        Packet size in bytes on the selected stream channel. Excludes data leader and data trailer. (The last packet may be smaller because the packet size is not necessarily a multiple of the block size of the stream channel.)
    
        Visibility: Beginner

        Selected by: GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCPSPacketSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCPSPacketSize;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Second URL reference to the GenICam XML file - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSecondURL" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& GevSecondURL;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Number of stream channels supported by the camera - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevStreamChannelCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevStreamChannelCount;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Sets the stream channel to be configured - Applies to: acA2440-20gc

        Sets the stream channels to be configured. All changes to the stream channel settings will be applied to the selected stream channel.
    
        Visibility: Guru

        Selecting Parameters: GevSCPInterfaceIndex, GevGVSPExtendedIDMode, GevSCPHostPort, GevSCPSFireTestPacket, GevSCPSDoNotFragment, GevSCPSBigEndian, GevSCPSPacketSize, GevSCPD, GevSCFTD, GevSCDA, GevSCBWR, GevSCBWRA, GevSCBWA, GevSCDMT, GevSCDCT and GevSCFJM

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevStreamChannelSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GevStreamChannelSelectorEnums>& GevStreamChannelSelector;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates whether the IEEE 1588 V2 Precision Time Protocol (PTP) is supported - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedIEEE1588" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedIEEE1588;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates whether the selected network interface supports DHCP IP addressing - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedIPConfigurationDHCP" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedIPConfigurationDHCP;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates whether the selected network interface supports auto IP addressing (also known as LLA) - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedIPConfigurationLLA" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedIPConfigurationLLA;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates whether the selected network interface supports fixed IP addressing (also known as persistent IP addressing) - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedIPConfigurationPersistentIP" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedIPConfigurationPersistentIP;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates whether multiple operations in a single message are supported - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedOptionalCommandsConcatenation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedOptionalCommandsConcatenation;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates whether EVENT_CMD and EVENT_ACK are supported - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedOptionalCommandsEVENT" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedOptionalCommandsEVENT;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates whether EVENTDATA_CMD and EVENTDATA_ACK are supported - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedOptionalCommandsEVENTDATA" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedOptionalCommandsEVENTDATA;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates whether PACKETRESEND_CMD is supported - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedOptionalCommandsPACKETRESEND" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedOptionalCommandsPACKETRESEND;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates whether WRITEMEM_CMD and WRITEMEM_ACK are supported - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedOptionalCommandsWRITEMEM" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedOptionalCommandsWRITEMEM;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Indicates whether this GVSP transmitter or receiver can support a 16-bit block ID - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedOptionalLegacy16BitBlockID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedOptionalLegacy16BitBlockID;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Latches the current timestamp value of the camera - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevTimestampControlLatch" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& GevTimestampControlLatch;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Resets the timestamp control latch - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevTimestampControlLatchReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& GevTimestampControlLatchReset;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Resets the timestamp value of the camera - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevTimestampControlReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& GevTimestampControlReset;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Number of timestamp clock ticks in 1 second - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevTimestampTickFrequency" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevTimestampTickFrequency;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Latched value of the timestamp - Applies to: acA2440-20gc

        Latched value of the timestamp. (The timestamp must first be latched using the Timestamp Control Latch command.)
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevTimestampValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevTimestampValue;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Major version number of the GigE Vision specification supported by this camera - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevVersionMajor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevVersionMajor;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Minor version number of the GigE Vision specification supported by this camera - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevVersionMinor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevVersionMinor;

    //@}


    //! \name Categories: AutoFunctions
    //@{
    /*!
        \brief Gray value adjustment damping factor to be applied - Applies to: acA2440-20gc

        Gray value adjustment damping factor to be applied. This controls the speed with which pixel gray values are changed when Exposure Auto, Gain Auto, or both are enabled. This can be useful, for example, when objects move into the camera's field of view and the light conditions are changing gradually due to the moving objects.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GrayValueAdjustmentDampingAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& GrayValueAdjustmentDampingAbs;

    //@}


    //! \name Categories: AutoFunctions
    //@{
    /*!
        \brief Gray value adjustment damping factor (raw value) to be applied - Applies to: acA2440-20gc

        Gray value adjustment damping factor (raw value) to be applied. This controls the speed with which pixel gray values are changed when Exposure Auto, Gain Auto, or both are enabled. This can be useful, for example, when objects move into the camera's field of view and the light conditions are changing gradually due to the moving objects.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GrayValueAdjustmentDampingRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GrayValueAdjustmentDampingRaw;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Height of the camera's region of interest (area of interest) in pixels - Applies to: acA2440-20gc

        Height of the camera's region of interest (area of interest) in pixels. Depending on the camera model, the parameter can be set in different increments.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Height" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Height;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Maximum height of the region of interest (area of interest) in pixels - Applies to: acA2440-20gc

        Maximum height of the region of interest (area of interest) in pixels. The value takes into account any features that may limit the maximum height, e.g., binning.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=HeightMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& HeightMax;

    //@}


    //! \name Categories: LUTControls
    //@{
    /*!
        \brief Enables the selected lookup table (LUT) - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: LUTSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LUTEnable;

    //@}


    //! \name Categories: LUTControls
    //@{
    /*!
        \brief Pixel value to be replaced with the LUT Value pixel value - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: LUTSelector

        Selecting Parameters: LUTValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LUTIndex;

    //@}


    //! \name Categories: LUTControls
    //@{
    /*!
        \brief Sets the lookup table (LUT) to be configured - Applies to: acA2440-20gc

        Sets the lookup table (LUT) to be configured. All changes to the LUT settings will be applied to the selected LUT.
    
        Visibility: Beginner

        Selecting Parameters: LUTEnable, LUTIndex, LUTValue and LUTValueAll

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LUTSelectorEnums>& LUTSelector;

    //@}


    //! \name Categories: LUTControls
    //@{
    /*!
        \brief New pixel value to replace the LUT Index pixel value - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: LUTSelector and LUTIndex

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LUTValue;

    //@}


    //! \name Categories: LUTControls
    //@{
    /*!
        \brief A single register that lets you access all LUT entries - Applies to: acA2440-20gc

        A single register that lets you access all LUT entries. In many cases, this is faster than repeatedly changing individual entries in the LUT.
    
        Visibility: Expert

        Selected by: LUTSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTValueAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IRegisterEx& LUTValueAll;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Indicates the last error code in the memory - Applies to: acA2440-20gc

        Indicates the last error code in the memory. To delete the last error code from the list of error codes, use the Clear Last Error command.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LastError" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LastErrorEnums>& LastError;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets the type of light source for which color transformation will be performed - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: ColorTransformationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LightSourceSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LightSourceSelectorEnums>& LightSourceSelector;

    //@}


    //! \name Categories: Line1RisingEdgeEventData
    //@{
    /*!
        \brief Stream channel index of the Line 1 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line1RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line1RisingEdgeEventStreamChannelIndex;

    //@}


    //! \name Categories: Line1RisingEdgeEventData
    //@{
    /*!
        \brief Timestamp of the Line 1 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line1RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line1RisingEdgeEventTimestamp;

    //@}


    //! \name Categories: Line2RisingEdgeEventData
    //@{
    /*!
        \brief Stream channel index of the Line 2 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line2RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line2RisingEdgeEventStreamChannelIndex;

    //@}


    //! \name Categories: Line2RisingEdgeEventData
    //@{
    /*!
        \brief Timestamp of the Line 2 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line2RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line2RisingEdgeEventTimestamp;

    //@}


    //! \name Categories: Line3RisingEdgeEventData
    //@{
    /*!
        \brief Stream channel index of the Line 3 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line3RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line3RisingEdgeEventStreamChannelIndex;

    //@}


    //! \name Categories: Line3RisingEdgeEventData
    //@{
    /*!
        \brief Timestamp of the Line 3 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line3RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line3RisingEdgeEventTimestamp;

    //@}


    //! \name Categories: Line4RisingEdgeEventData
    //@{
    /*!
        \brief Stream channel index of the Line 4 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line4RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line4RisingEdgeEventStreamChannelIndex;

    //@}


    //! \name Categories: Line4RisingEdgeEventData
    //@{
    /*!
        \brief Timestamp of the Line 4 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line4RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line4RisingEdgeEventTimestamp;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Line debouncer time in microseconds - Applies to: acA2440-20gc

        Line debouncer time in microseconds. The Line Debouncer allows you to filter out invalid hardware signals by specifying a minimum signal length.
    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineDebouncerTimeAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& LineDebouncerTimeAbs;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Indicates the electrical configuration of the currently selected line - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineFormat" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineFormatEnums>& LineFormat;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Enables the signal inverter function for the currently selected input or output line - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineInverter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LineInverter;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Indicates the line logic of the currently selected line - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineLogic" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineLogicEnums>& LineLogic;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Sets the mode for the selected line - Applies to: acA2440-20gc

        Sets the mode for the selected line. This controls whether the physical line is used to input or output a signal.
    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineModeEnums>& LineMode;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Sets the I/O line to be configured - Applies to: acA2440-20gc

        Sets the I/O line to be configured. All changes to the line settings will be applied to the selected line.
    
        Visibility: Beginner

        Selecting Parameters: LineMode, LineDebouncerTimeAbs, LineDebouncerTimeRaw, LineInverter, LineTermination, LineStatus, LineSource, LineFormat, MinOutPulseWidthAbs and MinOutPulseWidthRaw

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineSelectorEnums>& LineSelector;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Sets the source signal for the currently selected line - Applies to: acA2440-20gc

        Sets the source signal for the currently selected line. The currently selected line must be an output line.
    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineSourceEnums>& LineSource;

    //@}


    //! \name Categories: LineStartOvertriggerEventData
    //@{
    /*!
        \brief Stream channel index of the Line Start Overtrigger event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineStartOvertriggerEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LineStartOvertriggerEventStreamChannelIndex;

    //@}


    //! \name Categories: LineStartOvertriggerEventData
    //@{
    /*!
        \brief Timestamp of the Line Start Overtrigger event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineStartOvertriggerEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LineStartOvertriggerEventTimestamp;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Indicates the current logical state of the selected line - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LineStatus;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Single bit field indicating the current logical state of all available line signals at time of polling - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineStatusAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LineStatusAll;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Enables the termination resistor of the selected input line - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineTermination" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LineTermination;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Minimum signal width of an output signal (in microseconds) - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=MinOutPulseWidthAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& MinOutPulseWidthAbs;

    //@}


    //! \name Categories: PGIControl
    //@{
    /*!
        \brief Amount of noise reduction to be applied - Applies to: acA2440-20gc

        Amount of noise reduction to be applied. The higher the value, the less chroma noise will be visible in your images. However, excessively high values may result in image information loss.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=NoiseReductionAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& NoiseReductionAbs;

    //@}


    //! \name Categories: PGIControl
    //@{
    /*!
        \brief Amount of noise reduction to be applied (raw value) - Applies to: acA2440-20gc

        Amount of noise reduction to be applied (raw value). The higher the value, the less chroma noise will be visible in your images. However, excessively high values may result in image information loss.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=NoiseReductionRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& NoiseReductionRaw;

    //@}


    //! \name Categories: ActionControl
    //@{
    /*!
        \brief Number of separate action signals supported by the camera - Applies to: acA2440-20gc

        Number of separate action signals supported by the camera. Determines how many action signals the camera can handle in parallel, i.e., how many different action commands can be configured on the camera.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=NumberOfActionSignals" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& NumberOfActionSignals;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Horizontal offset of the region of interest (area of interest) from the left side of the sensor (in pixels) - Applies to: acA2440-20gc

        Horizontal offset from the left side of the sensor to the region of interest (area of interest) (in pixels).
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OffsetX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& OffsetX;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Vertical offset of the region of interest (area of interest) from the top of the sensor (in pixels) - Applies to: acA2440-20gc

        Vertical offset from the top of the sensor to the region of interest (area of interest) (in pixels).
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OffsetY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& OffsetY;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Indicates whether an over temperature state has been detected - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OverTemperature" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& OverTemperature;

    //@}


    //! \name Categories: OverTemperatureEventData
    //@{
    /*!
        \brief Stream channel index of the Over Temperature event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OverTemperatureEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& OverTemperatureEventStreamChannelIndex;

    //@}


    //! \name Categories: OverTemperatureEventData
    //@{
    /*!
        \brief Timestamp of the Over Temperature event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OverTemperatureEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& OverTemperatureEventTimestamp;

    //@}


    //! \name Categories: RemoveParamLimits
    //@{
    /*!
        \brief Sets the parameter whose factory limits can be removed - Applies to: acA2440-20gc

        Sets the parameter whose factory limits can be removed. The factory limits can be removed using the Remove Limits parameter.
    
        Visibility: Guru

        Selecting Parameters: RemoveLimits

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ParameterSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ParameterSelectorEnums>& ParameterSelector;

    //@}


    //! \name Categories: TransportLayer
    //@{
    /*!
        \brief Size of the payload in bytes - Applies to: acA2440-20gc

        Size of the payload in bytes. This is the total number of bytes sent in the payload.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PayloadSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PayloadSize;

    //@}


    //! \name Categories: PGIControl
    //@{
    /*!
        \brief Enables Basler PGI image optimizations - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PgiMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PgiModeEnums>& PgiMode;

    //@}


    //! \name Categories: ImageFormat
    //@{
    /*!
        \brief Indicates the alignment of the camera's Bayer filter to the pixels in the acquired images - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelColorFilter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PixelColorFilterEnums>& PixelColorFilter;

    //@}


    //! \name Categories: ImageFormat
    //@{
    /*!
        \brief Maximum possible pixel value that can be transferred from the camera - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelDynamicRangeMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PixelDynamicRangeMax;

    //@}


    //! \name Categories: ImageFormat
    //@{
    /*!
        \brief Minimum possible pixel value that can be transferred from the camera - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelDynamicRangeMin" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PixelDynamicRangeMin;

    //@}


    //! \name Categories: ImageFormat
    //@{
    /*!
        \brief Sets the format of the pixel data transmitted by the camera - Applies to: acA2440-20gc

        Sets the format of the pixel data transmitted by the camera. The available pixel formats depend on the camera model and whether the camera is monochrome or color.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelFormat" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PixelFormatEnums>& PixelFormat;

    //@}


    //! \name Categories: ImageFormat
    //@{
    /*!
        \brief Indicates the depth of the pixel values in the image (in bits per pixel) - Applies to: acA2440-20gc

        Indicates the depth of the pixel values in the image (in bits per pixel). The potential values depend on the pixel format setting.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PixelSizeEnums>& PixelSize;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Enables or disables the currently selected ROI zone - Applies to: acA2440-20gc

        Enables the output of color-improved raw image data. If enabled, color transformation and color adjustment will be applied to Bayer pixel formats.
    
        Visibility: Expert

        Selected by: ROIZoneSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ROIZoneMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ROIZoneModeEnums>& ROIZoneMode;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Vertical offset of the currently selected ROI zone - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: ROIZoneSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ROIZoneOffset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ROIZoneOffset;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Sets the ROI zone that can be configured - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selecting Parameters: ROIZoneMode, ROIZoneSize and ROIZoneOffset

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ROIZoneSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ROIZoneSelectorEnums>& ROIZoneSelector;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Height of the currently selected ROI zone - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: ROIZoneSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ROIZoneSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ROIZoneSize;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Sensor readout time with current settings - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ReadoutTimeAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ReadoutTimeAbs;

    //@}


    //! \name Categories: RemoveParamLimits
    //@{
    /*!
        \brief Removes the factory-set limit of the selected parameter - Applies to: acA2440-20gc

        Removes the factory-set limit of the selected parameter. If the factory limits are removed, a wider range of parameter values is available and only subect to technical restrictions. Choosing parameter values outside of the factory limits may affect image quality.
    
        Visibility: Guru

        Selected by: ParameterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=RemoveLimits" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& RemoveLimits;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Maximum frame acquisition period with current camera settings - Applies to: acA2440-20gc

        Maximum frame acquisition period with current camera settings (in microseconds).
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ResultingFramePeriodAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ResultingFramePeriodAbs;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Maximum frame acquisition rate with current camera settings - Applies to: acA2440-20gc

        Maximum frame acquisition rate with current camera settings (in frames per second).
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ResultingFrameRateAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ResultingFrameRateAbs;

    //@}


    //! \name Categories: ImageFormat
    //@{
    /*!
        \brief Enables horizontal mirroring of the image - Applies to: acA2440-20gc

        Enables horizontal mirroring of the image. The pixel values of every line in a captured image will be swapped along the line's center. You can use the ROI feature when using the Reverse X feature. The position of the ROI relative to the sensor remains the same.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ReverseX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ReverseX;

    //@}


    //! \name Categories: ImageFormat
    //@{
    /*!
        \brief Enables vertical mirroring of the image - Applies to: acA2440-20gc

        Enables vertical mirroring of the image. The pixel values of every column in a captured image will be swapped along the column's center. You can use the ROI feature when using the Reverse Y feature. The position of the ROI relative to the sensor remains the same.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ReverseY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ReverseY;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Horizontal scaling factor - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ScalingHorizontalAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ScalingHorizontalAbs;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Vertical scaling factor - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ScalingVerticalAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ScalingVerticalAbs;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Height of the camera's sensor in pixels - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorHeight" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SensorHeight;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Sets the sensor readout mode - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorReadoutMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SensorReadoutModeEnums>& SensorReadoutMode;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Width of the camera's sensor in pixels - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SensorWidth;

    //@}


    //! \name Categories: SequenceControlConfiguration
    //@{
    /*!
        \brief Sets which bit of the sequence set address can be assigned to an input line - Applies to: acA2440-20gc

        Sets which bit of the sequence set address can be assigned to an input line. An input line can be set as the control source for this bit using the Address Bit Source parameter.
    
        Visibility: Guru

        Selecting Parameters: SequenceAddressBitSource

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceAddressBitSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequenceAddressBitSelectorEnums>& SequenceAddressBitSelector;

    //@}


    //! \name Categories: SequenceControlConfiguration
    //@{
    /*!
        \brief Sets an input line as the control source for the currently selected sequence set address bit - Applies to: acA2440-20gc

        Sets an input line as the control source for the currently selected sequence set address bit. The bit can be selected using the Address Bit Selector parameter.
    
        Visibility: Guru

        Selected by: SequenceAddressBitSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceAddressBitSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequenceAddressBitSourceEnums>& SequenceAddressBitSource;

    //@}


    //! \name Categories: SequenceControlConfiguration
    //@{
    /*!
        \brief Sets the sequence set advance mode - Applies to: acA2440-20gc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceAdvanceMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequenceAdvanceModeEnums>& SequenceAdvanceMode;

    //@}


    //! \name Categories: SequenceControl
    //@{
    /*!
        \brief Enables asynchronous advance from one sequence set to the next - Applies to: acA2440-20gc

        Enables asynchronous advance from one sequence set to the next. The advance is asynchronous to the camera's frame trigger. Only available in Controlled sequence advance mode.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceAsyncAdvance" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SequenceAsyncAdvance;

    //@}


    //! \name Categories: SequenceControl
    //@{
    /*!
        \brief Enables asynchronous restart of the sequence set sequence - Applies to: acA2440-20gc

        Enables asynchronous restart of the sequence set sequence, starting with the sequence set that has the lowest index number. The restart is asynchronous to the camera's frame trigger. Only available in Auto and Controlled sequence advance mode.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceAsyncRestart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SequenceAsyncRestart;

    //@}


    //! \name Categories: SequenceControl
    //@{
    /*!
        \brief Sets whether the sequencer can be configured - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceConfigurationMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequenceConfigurationModeEnums>& SequenceConfigurationMode;

    //@}


    //! \name Categories: SequenceControlConfiguration
    //@{
    /*!
        \brief Sets whether sequence advance or sequence restart can be configured - Applies to: acA2440-20gc

        Sets whether sequence advance or sequence restart can be configured. A control source must be chosen using the Sequence Control Source parameter.
    
        Visibility: Guru

        Selecting Parameters: SequenceControlSource

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceControlSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequenceControlSelectorEnums>& SequenceControlSelector;

    //@}


    //! \name Categories: SequenceControlConfiguration
    //@{
    /*!
        \brief Sets the source for sequence control - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selected by: SequenceControlSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceControlSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequenceControlSourceEnums>& SequenceControlSource;

    //@}


    //! \name Categories: SequenceControl
    //@{
    /*!
        \brief Current sequence set - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceCurrentSet" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequenceCurrentSet;

    //@}


    //! \name Categories: SequenceControl
    //@{
    /*!
        \brief Enables the sequencer - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& SequenceEnable;

    //@}


    //! \name Categories: SequenceControl
    //@{
    /*!
        \brief Number of sequence set executions - Applies to: acA2440-20gc

        Number of consecutive executions per sequence cycle of the selected sequence set. Only available in Auto sequence advance mode.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceSetExecutions" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequenceSetExecutions;

    //@}


    //! \name Categories: SequenceControl
    //@{
    /*!
        \brief Index number of a sequence set - Applies to: acA2440-20gc

        This number uniquely identifies a sequence set.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceSetIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequenceSetIndex;

    //@}


    //! \name Categories: SequenceControl
    //@{
    /*!
        \brief Loads a sequence set - Applies to: acA2440-20gc

        Loads an existing sequence set to make it the current sequence set.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceSetLoad" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SequenceSetLoad;

    //@}


    //! \name Categories: SequenceControl
    //@{
    /*!
        \brief Stores the current sequence set - Applies to: acA2440-20gc

        Stores the current sequence set. Storing the current sequence set will overwrite any existing sequence set with the same index number. The sequence set is stored in the volatile memory and will therefore be lost if the camera is reset or if power is switched off.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceSetStore" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SequenceSetStore;

    //@}


    //! \name Categories: SequenceControl
    //@{
    /*!
        \brief Total number of sequence sets in the sequence - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceSetTotalNumber" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequenceSetTotalNumber;

    //@}


    //! \name Categories: PGIControl
    //@{
    /*!
        \brief Sharpening value to be applied - Applies to: acA2440-20gc

        Sharpening value to be applied. The higher the sharpness, the more distinct the image subject's contours will be. However, excessively high values may result in image information loss.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SharpnessEnhancementAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& SharpnessEnhancementAbs;

    //@}


    //! \name Categories: PGIControl
    //@{
    /*!
        \brief Sharpening value to be applied (raw value) - Applies to: acA2440-20gc

        Sharpening value to be applied (raw value). The higher the sharpness, the more distinct the image subject's contours will be. However, excessively high values may result in image information loss.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SharpnessEnhancementRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SharpnessEnhancementRaw;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Sets the shutter mode of the camera - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShutterMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ShutterModeEnums>& ShutterMode;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Enables the synchronous free run mode - Applies to: acA2440-20gc

        Enables the synchronous free run mode. If enabled, the camera will generate all required frame start or line start trigger signals internally. You don't need to apply frame start or line start trigger signals to the camera.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncFreeRunTimerEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& SyncFreeRunTimerEnable;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief High 32 bits of the synchronous free run trigger start time - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncFreeRunTimerStartTimeHigh" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SyncFreeRunTimerStartTimeHigh;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Low 32 bits of the synchronous free run trigger start time - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncFreeRunTimerStartTimeLow" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SyncFreeRunTimerStartTimeLow;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Synchronous free run trigger rate - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncFreeRunTimerTriggerRateAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& SyncFreeRunTimerTriggerRateAbs;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Updates synchronous free run settings - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncFreeRunTimerUpdate" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SyncFreeRunTimerUpdate;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Sets the user-settable synchronous output signal to be configured - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selecting Parameters: SyncUserOutputValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncUserOutputSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SyncUserOutputSelectorEnums>& SyncUserOutputSelector;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Enables the selected user-settable synchronous output line - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: SyncUserOutputSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncUserOutputValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& SyncUserOutputValue;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Single bit field that sets the state of all user-settable synchronous output signals in one access - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncUserOutputValueAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SyncUserOutputValueAll;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Temperature at the selected location in the camera (in degrees centigrade) - Applies to: acA2440-20gc

        Temperature at the selected location in the camera (in degrees centigrade). The temperature is measured at the location specified by the Temperature Selector parameter.
    
        Visibility: Expert

        Selected by: TemperatureSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TemperatureAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TemperatureAbs;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Sets the location in the camera where the temperature will be measured - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selecting Parameters: TemperatureAbs

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TemperatureSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TemperatureSelectorEnums>& TemperatureSelector;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Indicates the temperature state - Applies to: acA2440-20gc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TemperatureState" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TemperatureStateEnums>& TemperatureState;

    //@}


    //! \name Categories: ImageFormat
    //@{
    /*!
        \brief Allows you to turn a moving test image into a fixed one - Applies to: acA2440-20gc

        Allows you to turn a moving test image into a fixed one. The test image will be displayed at its starting position and will stay fixed.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TestImageResetAndHold" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& TestImageResetAndHold;

    //@}


    //! \name Categories: ImageFormat
    //@{
    /*!
        \brief Sets the test image to display - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TestImageSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TestImageSelectorEnums>& TestImageSelector;

    //@}


    //! \name Categories: TimerControls
    //@{
    /*!
        \brief Delay of the currently selected timer in microseconds - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDelayAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TimerDelayAbs;

    //@}


    //! \name Categories: TimerControls
    //@{
    /*!
        \brief Delay of the selected timer (raw value) - Applies to: acA2440-20gc

        Delay of the selected timer (raw value). This value will be used as a multiplier for the timer delay timebase. The actual delay time equals the current Timer Delay Raw value multiplied with the current Timer Delay Timebase value.
    
        Visibility: Beginner

        Selected by: TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDelayRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TimerDelayRaw;

    //@}


    //! \name Categories: TimerControls
    //@{
    /*!
        \brief Duration of the currently selected timer in microseconds - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDurationAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TimerDurationAbs;

    //@}


    //! \name Categories: TimerControls
    //@{
    /*!
        \brief Duration of the selected timer (raw value) - Applies to: acA2440-20gc

        Duration of the selected timer (raw value). This value will be used as a multiplier for the timer duration timebase. The actual duration time equals the current Timer Duration Raw value multiplied with the current Timer Duration Timebase value.
    
        Visibility: Beginner

        Selected by: TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDurationRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TimerDurationRaw;

    //@}


    //! \name Categories: TimerControls
    //@{
    /*!
        \brief Sets the timer to be configured - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selecting Parameters: TimerDurationAbs, TimerDurationRaw, TimerDelayAbs, TimerDelayRaw, TimerTriggerSource and TimerTriggerActivation

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TimerSelectorEnums>& TimerSelector;

    //@}


    //! \name Categories: TimerControls
    //@{
    /*!
        \brief Sets the type of signal transition that will start the timer - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerTriggerActivation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TimerTriggerActivationEnums>& TimerTriggerActivation;

    //@}


    //! \name Categories: TimerControls
    //@{
    /*!
        \brief Sets the internal camera signal used to trigger the selected timer - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerTriggerSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TimerTriggerSourceEnums>& TimerTriggerSource;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Sets the type of signal transition that will activate the selected trigger - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerActivation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerActivationEnums>& TriggerActivation;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Trigger delay time in microseconds - Applies to: acA2440-20gc

        Trigger delay time in microseconds. The delay is applied after the trigger has been received and before effectively activating the trigger.
    
        Visibility: Expert

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerDelayAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TriggerDelayAbs;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Sets the mode for the currently selected trigger - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerModeEnums>& TriggerMode;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Sets the trigger type to be configured - Applies to: acA2440-20gc

        Sets the trigger type to be configured. All changes to the trigger settings will be applied to the selected trigger.
    
        Visibility: Expert

        Selecting Parameters: TriggerMode, TriggerSoftware, TriggerSource, TriggerActivation and TriggerDelayAbs

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerSelectorEnums>& TriggerSelector;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Generates a software trigger signal - Applies to: acA2440-20gc

        Generates a software trigger signal. The software trigger signal will be used if the Trigger Source parameter is set to Trigger Software.
    
        Visibility: Expert

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerSoftware" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& TriggerSoftware;

    //@}


    //! \name Categories: AcquisitionTrigger
    //@{
    /*!
        \brief Sets the source signal for the selected trigger - Applies to: acA2440-20gc

    
        Visibility: Expert

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerSourceEnums>& TriggerSource;

    //@}


    //! \name Categories: UserDefinedValues
    //@{
    /*!
        \brief User-defined value - Applies to: acA2440-20gc

        User-defined value. The value can serve as storage location for the camera user. It has no impact on the operation of the camera.
    
        Visibility: Guru

        Selected by: UserDefinedValueSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserDefinedValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& UserDefinedValue;

    //@}


    //! \name Categories: UserDefinedValues
    //@{
    /*!
        \brief Sets the user-defined value to set or read - Applies to: acA2440-20gc

    
        Visibility: Guru

        Selecting Parameters: UserDefinedValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserDefinedValueSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserDefinedValueSelectorEnums>& UserDefinedValueSelector;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Sets the user-settable output signal to be configured - Applies to: acA2440-20gc

        Sets the user-settable output signal to be configured. All changes to the user-settable output signal settings will be applied to the selected user-settable output signal.
    
        Visibility: Beginner

        Selecting Parameters: UserOutputValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserOutputSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserOutputSelectorEnums>& UserOutputSelector;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Enables the selected user-settable output line - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: UserOutputSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserOutputValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& UserOutputValue;

    //@}


    //! \name Categories: DigitalIO
    //@{
    /*!
        \brief Single bit field that sets the state of all user-settable output signals in one access - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserOutputValueAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& UserOutputValueAll;

    //@}


    //! \name Categories: UserSets
    //@{
    /*!
        \brief Sets the user set or the factory set to be used as the startup set - Applies to: acA2440-20gc

        Sets the user set or the factory set to be used as the startup set. The default startup set will be loaded as the active set whenever the camera is powered on or reset.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetDefaultSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserSetDefaultSelectorEnums>& UserSetDefaultSelector;

    //@}


    //! \name Categories: UserSets
    //@{
    /*!
        \brief Loads the selected set into the camera's volatile memory and makes it the active configuration set - Applies to: acA2440-20gc

        Loads the selected set into the camera's volatile memory and makes it the active configuration set. After the selected set has been loaded, the parameters in that set will control the camera.
    
        Visibility: Beginner

        Selected by: UserSetSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetLoad" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& UserSetLoad;

    //@}


    //! \name Categories: UserSets
    //@{
    /*!
        \brief Saves the current active set as the selected user set - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selected by: UserSetSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetSave" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& UserSetSave;

    //@}


    //! \name Categories: UserSets
    //@{
    /*!
        \brief Sets the user set or the factory set to load, save, or configure - Applies to: acA2440-20gc

    
        Visibility: Beginner

        Selecting Parameters: UserSetLoad and UserSetSave

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserSetSelectorEnums>& UserSetSelector;

    //@}


    //! \name Categories: VignettingCorrectionControl
    //@{
    /*!
        \brief Loads the vignetting correction data - Applies to: acA2440-20gc

        Loads the vignetting correction data into the camera.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VignettingCorrectionLoad" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& VignettingCorrectionLoad;

    //@}


    //! \name Categories: VignettingCorrectionControl
    //@{
    /*!
        \brief Enables/disables the vignetting correction - Applies to: acA2440-20gc

        The Vignetting Correction feature allows you to remove vignetting artifacts from your images. To do this, you first have to create vignetting correction data. For more information, see the Basler Product Documentation.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VignettingCorrectionMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<VignettingCorrectionModeEnums>& VignettingCorrectionMode;

    //@}


    //! \name Categories: VirtualLine1RisingEdgeEventData
    //@{
    /*!
        \brief Stream channel index of the Virtual Line 1 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine1RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine1RisingEdgeEventStreamChannelIndex;

    //@}


    //! \name Categories: VirtualLine1RisingEdgeEventData
    //@{
    /*!
        \brief Timestamp of the Virtual Line 1 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine1RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine1RisingEdgeEventTimestamp;

    //@}


    //! \name Categories: VirtualLine2RisingEdgeEventData
    //@{
    /*!
        \brief Stream channel index of the Virtual Line 2 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine2RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine2RisingEdgeEventStreamChannelIndex;

    //@}


    //! \name Categories: VirtualLine2RisingEdgeEventData
    //@{
    /*!
        \brief Timestamp of the Virtual Line 2 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine2RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine2RisingEdgeEventTimestamp;

    //@}


    //! \name Categories: VirtualLine3RisingEdgeEventData
    //@{
    /*!
        \brief Stream channel index of the Virtual Line 3 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine3RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine3RisingEdgeEventStreamChannelIndex;

    //@}


    //! \name Categories: VirtualLine3RisingEdgeEventData
    //@{
    /*!
        \brief Timestamp of the Virtual Line 3 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine3RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine3RisingEdgeEventTimestamp;

    //@}


    //! \name Categories: VirtualLine4RisingEdgeEventData
    //@{
    /*!
        \brief Stream channel index of the Virtual Line 4 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine4RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine4RisingEdgeEventStreamChannelIndex;

    //@}


    //! \name Categories: VirtualLine4RisingEdgeEventData
    //@{
    /*!
        \brief Timestamp of the Virtual Line 4 Rising Edge event - Applies to: acA2440-20gc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine4RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine4RisingEdgeEventTimestamp;

    //@}


    //! \name Categories: AOI
    //@{
    /*!
        \brief Width of the camera's region of interest (area of interest) in pixels - Applies to: acA2440-20gc

        Width of the camera's region of interest (area of interest) in pixels. Depending on the camera model, the parameter can be set in different increments.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Width" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Width;

    //@}


    //! \name Categories: DeviceInformation
    //@{
    /*!
        \brief Maximum width of the region of interest (area of interest) in pixels - Applies to: acA2440-20gc

        Maximum width of the region of interest (area of interest) in pixels. The value takes into account any function that may limit the maximum width.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=WidthMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& WidthMax;

    //@}


        private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            BaslerCameraCameraParams(BaslerCameraCameraParams&);

            //! not implemented assignment operator
            BaslerCameraCameraParams& operator=(BaslerCameraCameraParams&);

        //! \endcond
    };

} // namespace Pylon
} // namespace BaslerCameraCameraParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_BASLERCAMERACAMERAPARAMS_H