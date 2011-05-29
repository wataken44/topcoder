template<typename PT, typename DT>
class PQ {
 public:
  typedef PT priority_type;
  typedef DT data_type;
  typedef std::pair<priority_type, data_type> pair_type;
  typedef std::list<pair_type> list_type;
  typedef typename list_type::iterator iterator;
  typedef typename list_type::const_iterator const_iterator;
  
  PQ() {}
  virtual ~PQ() {}

  int size() const { return m_body.size(); }
  bool empty() const { return size() == 0; }
  void pop() { m_body.pop_front(); }
  data_type& front() const { return m_body.front()->second; }

  iterator begin() { return m_body.begin(); }
  iterator end() { return m_body.end(); }
  const_iterator begin() const { return m_body.begin(); }
  const_iterator end() const { return m_body.end(); }

  void push(const priority_type& p, const data_type& d)
  {
    iterator iter = find(d);
    if(iter != end()) {
      if(iter->first > p) {
        m_body.erase(iter);
        add(p, d);
      }
    }else {
      add(p, d);
    }
  }
  
  void add(const priority_type& p, const data_type& d)
  {
    for(iterator iter = begin(); iter != end(); ++iter) {
      if(iter->first > p) {
        m_body.insert(iter, std::make_pair(p, d));
        return;
      }
    }
    m_body.push_back(std::make_pair(p, d));
  }

  void remove(const data_type& d) {
    iterator iter = find(d);
    if(iter != end()) {
      m_body.erase(iter);
    }
  }

  iterator find(const data_type& d)
  {
    for(iterator iter = begin(); iter != end(); ++iter) {
      if(iter->second == d) {
        return iter;
      }
    }
    return end();
  }
  
 private:
  list_type m_body;
};
