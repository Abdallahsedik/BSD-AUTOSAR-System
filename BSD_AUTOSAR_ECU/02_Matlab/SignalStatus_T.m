classdef SignalStatus_T < Simulink.IntEnumType
    enumeration
        SIGNAL_OK (0) % Signal is valid and can be used by the algorithm
        SIGNAL_FAIL (1) % Signal is invalid, undefined, or missing and shall not be used
    end
    methods (Static = true)
        function retVal = getDefaultVal()
            retVal = SignalStatus_T.SIGNAL_OK; 
        end
        function headerFile = getHeaderFile()
            headerFile = 'Rte_Type.h'; 
        end
        function dataScope = getDataScope()
            dataScope = 'Imported'; 
        end
        function storageType = getStorageType()
            storageType = 'uint8'; 
        end
    end
end