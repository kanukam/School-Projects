#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include "DataType.h"

class ArrayList{
	
  friend std::ostream & operator<<(std::ostream & os,const ArrayList & arrayList);
						   
  public:
    ArrayList();								    		//(1)
    ArrayList(size_t count, const DataType & value);		//(2)
    ArrayList(const ArrayList & other);				    	//(3)
   ~ArrayList();							    			//(4)

    ArrayList & operator= (const ArrayList & rhs);			//(5)


    DataType * front();							     		//(6)
    DataType * back();						                //(7)
	
    DataType * find(const DataType & target,DataType * & previous);	//(8)
	
    DataType * insertAfter(const DataType & target,const DataType & value);	 //(9)
    DataType * insertBefore(const DataType & target,const DataType & value);     //(10)
    DataType * erase(const DataType & target);		 		//(11)

	
    DataType & operator[] (size_t position);				//(12)
    
    size_t size() const;									//(13)
    bool empty() const;										//(14)
    void clear();											//(15)	


  private:
  
    void resize(size_t count);		               			//(16)					    
    DataType * m_array;
    size_t m_size;
    size_t m_maxsize;

};


#endif //ARRAYLIST_H_
