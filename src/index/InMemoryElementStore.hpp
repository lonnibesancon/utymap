#ifndef INDEX_INMEMORYELEMENTSTORE_HPP_DEFINED
#define INDEX_INMEMORYELEMENTSTORE_HPP_DEFINED

#include "QuadKey.hpp"
#include "entities/Element.hpp"
#include "index/ElementStore.hpp"
#include "index/StringTable.hpp"

#include <string>
#include <memory>

namespace utymap { namespace index {

// Provides API to store elements in memory.
class InMemoryElementStore : public ElementStore
{
public:
    InMemoryElementStore(StringTable& stringTable, const StyleFilter& styleFilter);

    ~InMemoryElementStore();

protected:
    StringTable& getStringTable() const;

    const StyleFilter& getStyleFilter() const;

    utymap::entities::ElementVisitor& getElementVisitor() const;

private:
    class InMemoryElementStoreImpl;
    std::unique_ptr<InMemoryElementStoreImpl> pimpl_;
};

}}

#endif // INDEX_INMEMORYELEMENTSTORE_HPP_DEFINED