classdef Gear_T < Simulink.IntEnumType
    enumeration
        GEAR_PARK (0) % Park
        GEAR_REVERSE (1) % Reverse
        GEAR_NEUTRAL (2) % Neutral
        GEAR_DRIVE (3) % Drive
    end
    methods (Static = true)
        function retVal = getDefaultVal()
            retVal = Gear_T.GEAR_PARK; 
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