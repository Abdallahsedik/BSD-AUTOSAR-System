classdef DiagEventStatus_T < Simulink.IntEnumType
    enumeration
        DIAG_EVT_PASSED (0) % Monitored signal is healthy
        DIAG_EVT_FAILED (1) % Monitored signal has failed
    end
    methods (Static = true)
        function retVal = getDefaultVal()
            retVal = DiagEventStatus_T.DIAG_EVT_PASSED;
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