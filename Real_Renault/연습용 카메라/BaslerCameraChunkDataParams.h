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

#ifndef BASLER_PYLON_BASLERCAMERACHUNKDATAPARAMS_H
#define BASLER_PYLON_BASLERCAMERACHUNKDATAPARAMS_H

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
namespace BaslerCameraChunkDataParams_Params
{
    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    //! Valid values for ChunkPixelFormat
    enum ChunkPixelFormatEnums
    {
        ChunkPixelFormat_Todo  //!< TODO - Applies to: acA2440-20gc
    };


    
    
    //**************************************************************************************************
    // Parameter class BaslerCameraChunkDataParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for acA2440-20gc

    Sources:
    acA2440-20gc 107213-21;U;acA2440_20g;V2.1-0;1
    */
    class BaslerCameraChunkDataParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            BaslerCameraChunkDataParams(void);

            //! Destructor
            ~BaslerCameraChunkDataParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class BaslerCameraChunkDataParams_Data;
        BaslerCameraChunkDataParams_Data* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Maximum possible pixel value in the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkDynamicRangeMax;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Minimum possible pixel value in the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkDynamicRangeMin;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Exposure time used to acquire the image - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IFloatEx& ChunkExposureTime;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Frame Trigger counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkFrameTriggerCounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Frame Trigger Ignored counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkFrameTriggerIgnoredCounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Frame counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkFramecounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Frames per Trigger counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkFramesPerTriggerCounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Gain All value of the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkGainAll;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief AOI height of the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkHeight;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Number of bits per line used for the Input Status At Line Trigger parameter - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkInputStatusAtLineTriggerBitsPerLine;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Index number used for the Input Status At Line Trigger parameter - Applies to: acA2440-20gc

        Index number used for the Input Status At Line Trigger parameter. The index number can be used to get the state of the camera's input lines when a specific line was acquired. For example, if you want to know the state of the camera's input lines when line 30 was acquired, set the index to 30, then retrieve the value of Status Index parameter.
    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkInputStatusAtLineTriggerIndex;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value indicating the status of the camera's input lines when a specific line was acquired - Applies to: acA2440-20gc

        Value indicating the status of the camera's input lines when a specific line was acquired. The information is stored in a 4-bit value (bit 0 = input line 1 state, bit 1 = input line 2 state etc.). For more information, see the Status Index parameter documentation.
    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkInputStatusAtLineTriggerValue;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Bit field that indicates the status of all of the camera's input and output lines when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkLineStatusAll;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Line Trigger counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkLineTriggerCounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Line Trigger End to End counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkLineTriggerEndToEndCounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Line Trigger Ignored counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkLineTriggerIgnoredCounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief X offset of the AOI of the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkOffsetX;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Y offset of the AOI of the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkOffsetY;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief CRC checksum of the acquired image - Applies to: acA2440-20gc

        CRC checksum of the acquired image. The checksum is calculated using all of the image data and all of the appended chunks except for the checksum itself.
    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkPayloadCRC16;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Indicates the pixel format of the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IEnumParameterT<ChunkPixelFormatEnums>& ChunkPixelFormat;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Sequence set index number related to the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkSequenceSetIndex;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Shaft Encoder counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkShaftEncoderCounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Number of bytes of data between the beginning of one line in the acquired image and the beginning of the next line in the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkStride;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the timestamp when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkTimestamp;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the Trigger Input counter when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkTriggerinputcounter;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Status of all of the camera's virtual input and output lines when the image was acquired - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkVirtLineStatusAll;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Width of the AOI of the acquired image - Applies to: acA2440-20gc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkWidth;

    //@}


        private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            BaslerCameraChunkDataParams(BaslerCameraChunkDataParams&);

            //! not implemented assignment operator
            BaslerCameraChunkDataParams& operator=(BaslerCameraChunkDataParams&);

        //! \endcond
    };

} // namespace Pylon
} // namespace BaslerCameraChunkDataParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_BASLERCAMERACHUNKDATAPARAMS_H