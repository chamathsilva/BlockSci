//
//  nonstandard_script.hpp
//  blocksci
//
//  Created by Harry Kalodner on 9/4/17.
//
//

#ifndef nonstandard_script_hpp
#define nonstandard_script_hpp

#include "script.hpp"
#include "script_view.hpp"

#include <range/v3/utility/optional.hpp>

namespace blocksci {
    template <>
    class ScriptAddress<AddressType::NONSTANDARD> : public ScriptBase<ScriptAddress<AddressType::NONSTANDARD>> {
        friend class ScriptBase<ScriptAddress<AddressType::NONSTANDARD>>;
        const NonstandardScriptData *rawData;
        const NonstandardSpendScriptData *rawInputData;
        
        ScriptAddress(uint32_t scriptNum, std::tuple<const NonstandardScriptData *, const NonstandardSpendScriptData *> &&rawData, const DataAccess &access);
        
        ranges::optional<CScriptView> getInputScript() const;
        CScriptView getOutputScript() const;
    public:
        constexpr static AddressType::Enum addressType = AddressType::NONSTANDARD;
        
        ScriptAddress(uint32_t addressNum, const DataAccess &access);
        
        std::string inputString() const;
        std::string outputString() const;
        
        std::string toString() const;
        std::string toPrettyString() const;
    };
}

#endif /* nonstandard_script_hpp */
