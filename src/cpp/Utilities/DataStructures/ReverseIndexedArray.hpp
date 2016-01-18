#include <vector>
#include <map>
#include <unordered_map>
namespace Axurez {
namespace DataStructure {


template <class TIndex, class TContent>
#ifdef AXUREZ_MAP_ORDERED_
class Map: public std::map<TIndex, TContent> {

};
#else
class Map: public std::unordered_map<TIndex, TContent> {

};
#endif

template <class TIndex, class TContent>
class RIA {
 private:
  std::vector<TContent> _content;
  std::map<TIndex, std::size_t> _indexMap; // TODO: map vs unordered_map
  Map<TContent, TIndex> _reverseIndex;
 public:
  RIA() {

  }

  ~RIA() {

  }

  const TContent& at(TIndex index) const {
    std::size_t nIndex;
    try {
      nIndex = _indexMap.at(index);
    } catch (std::out_of_range ex) {
      throw ex;
    }
    return _content.at(nIndex);
  }



  TContent& operator [](TIndex index) {

    if( this->_indexMap.find(index) == this->_indexMap.end()) {
      this->_indexMap[index] = this->_content.size();
      auto _newElem = TContent();
      this->_content.push_back(_newElem);
    }
    return this->_content.at(this->_indexMap.at(index));
  }

  int size() const {
    return this->_content.size();
  }
};

}
}