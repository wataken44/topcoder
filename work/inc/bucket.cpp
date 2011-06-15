template<typename IT, typename DT>
class Bucket {
 public:
  typedef IT index_type;
  typedef DT data_type;
  typedef std::pair<index_type, data_type> pair_type;
  typedef std::list<pair_type> list_type;
  typedef typename list_type::const_iterator const_iterator;
  typedef typename list_type::iterator iterator;

  class less {
   public:
    less(){}
    virtual ~less(){}
    bool operator()(const pair_type& lhs, const index_type& rhs)
    {
      return lhs.first < rhs;
    }
  };
  
  Bucket(index_type size, const data_type& data) : m_size(size), m_list()
  {
    m_list.push_back(make_pair(0,data));
  }
  virtual ~Bucket() { m_list.clear(); }

  const_iterator begin() const { return m_list.begin(); }
  const_iterator end() const { return m_list.end(); }
  iterator begin() { return m_list.begin(); }
  iterator end() { return m_list.end(); }

  iterator erase(iterator pos) { return m_list.erase(pos); }

  iterator remove(index_type pos)
  {
    return erase(find(pos));
  }

  iterator find(index_type pos)
  {
    iterator it = std::lower_bound(m_list.begin(), m_list.end(), pos, less());
    if(it != end() && it->first == pos) {
      return it;
    }
    --it;
    return it;
  }

  iterator divide(index_type pos)
  {
    iterator it = find(pos);
    if(it != m_list.end() && it->first != pos) {
      data_type& d = it->second;
      ++it;
      return m_list.insert(it, make_pair(pos, d));
    }else if(it == m_list.end()) {
      data_type& d = it->second;
      return m_list.insert(it, make_pair(pos, d));
    }

    return it;
  }

  index_type left(int pos) { return find(pos)->first; }
  index_type right(int pos)
  {
    iterator it = find(pos);
    ++it;
    return it == end() ? m_size : it->first;
  }
  
 private:
  index_type m_size;
  std::list<pair_type> m_list;
};
