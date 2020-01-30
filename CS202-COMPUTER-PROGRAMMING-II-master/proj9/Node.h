#ifndef NODE_H_
#define NODE_H_

#include "DataType.h"

class Node{

  friend class NodeQueue;  //allows direct accessing of link and data from class NodeList

  public:
    Node() :
	  m_next( NULL )
	{
	}
	Node(const DataType & data, Node * next = NULL) :
	  m_next( next ),
	  m_data( data )
	{
	}
	Node(const Node & other) :
	  m_next( other.m_next ),
	  m_data( other.m_data )
	{
	}
	
    DataType & data(){  //gets non-const reference, can be used to modify value of underlying data
      //return const_cast<DataType &>(static_cast<const Node &>(*this).getData());  //an alternative implementation, just for studying reference
	  return m_data;
    }
    const DataType & data() const{  //gets const reference, can be used to access value of underlying data
      return m_data;
    }

  private:
    Node * m_next; 						
    DataType m_data;
};
#endif //NODE_H_
