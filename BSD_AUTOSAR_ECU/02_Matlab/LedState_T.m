classdef LedState_T < Simulink.IntEnumType
    enumeration
        LED_OFF (0) 
        LED_ON (1) 
    end
    methods (Static = true)
        function retVal = getDefaultVal()
            retVal = LedState_T.TURN_ON; 
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