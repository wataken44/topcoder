template <typename Container, typename Comparator, typename Id>
class IdComparator {
  /*
    Comparator for sort_id function
   */
 public:
  IdComparator(const Container& cont, Comparator& comp)
      : cont_(cont), comp_(comp)
  {
    
  }
  virtual ~IdComparator() {}

  bool operator()(const Id& left, const Id& right) const
  {
    return comp_(cont_[left], cont_[right]);
  }
  
 private:
  const Container& cont_;
  Comparator& comp_;  
};

template <typename Container, typename Comparator>
void sort_id(
    const Container& container,
    Comparator comparator,
    std::vector<int>& result)
{
  /*
    sort 0..container.size() by comparator

    nth element of sort(container) is (result[n])th element of container 

    sort(container.begin(), container.end(), comparator)[n] ==
      container[result[n]]
    
    e.g.
      container = {12, 6, 24, 18, 42}
      comaprator = less<int>

      result = {1, 0, 3, 2, 4}

      (sort(container) = {6, 12, 18, 24, 42})
  */
  
  for(int i = 0; i < static_cast<int>(container.size()); ++i) {
    result.push_back(i);
  }

  std::sort(result.begin(), result.end(),
            IdComparator<Container, Comparator, int>(container, comparator));
}
