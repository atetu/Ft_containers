#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <memory>
#include <iostream>
#include <exception>


namespace ft
{

    template <class Iterator>
        class ReverseIterator : public Iterator
        {
        public:
            typedef Iterator							iterator_type;
			typedef typename Iterator::value_type		    value_type;
        //    typedef typename Iterator::const_value_type    const_value_type;
			typedef typename Iterator::pointer			pointer;
            typedef typename Iterator::const_pointer	const_pointer;
			typedef typename Iterator::reference		reference;
    

        public:
            ReverseIterator() : Iterator()
            {
            }

            ReverseIterator(const Iterator &it) : Iterator(it)
            {
                Iterator::operator--();
            }

            ReverseIterator(const Iterator &it, int option) : Iterator(it)
            {
                (void)option;
            }
            
            ReverseIterator(const ReverseIterator &other) : Iterator(other.node())
            {
            }

            ~ReverseIterator()
            {
            }

            ReverseIterator
            operator=(const ReverseIterator &other)
            {
                this->m_node = other.m_node;
                return (*this);
            }

            Iterator
            base() const
            {
                return (Iterator::base());
            }
            
            value_type&
            operator*() const
            {
                return (Iterator::operator*());
            }

            ReverseIterator
            operator+(int n) const
            {
                ReverseIterator copy(*this);
            
                return (copy.Iterator::operator-(n));
            }
            
            ReverseIterator
            operator++()
            {
                Iterator::operator--();
                return(*this);
            }

            ReverseIterator
            operator++(int)
            {
                ReverseIterator tmp(*this);
                operator++();
                return (tmp);
            }

            ReverseIterator
            operator+=(int n)
            {
                return(this->Iterator::operator-(n));
            }
            
            ReverseIterator
            operator-(int n) const
            {
                ReverseIterator copy(*this);
            
                return (copy.Iterator::operator+(n));
            }

            ReverseIterator
            operator--()
            {
                Iterator::operator++();
                return(*this);
            }
                
            ReverseIterator
            operator--(int)
            {
                ReverseIterator tmp(*this);
                operator--();
                return (tmp);
            }

            ReverseIterator
            operator-=(int n)
            {
                return(this->Iterator::operator+(n));
            }
            
            const_pointer operator->() const
            {
                return (Iterator::operator->());
            }
            reference operator[] (int n) const
            {
                return(this->Iterator::operator[](-n));
            }

        };

        template <class Iterator>
        bool operator== (const ReverseIterator<Iterator>& lhs,
        const ReverseIterator<Iterator>& rhs)
        {
            return(lhs.base() == rhs.base());
            //return(lhs.type() == *rhs);
        }

        template <class Iterator>
        bool operator!= (const ReverseIterator<Iterator>& lhs,
        const ReverseIterator<Iterator>& rhs)
        {
            return(lhs.base() != rhs.base());
        }

        template <class Iterator>
        bool operator< (const ReverseIterator<Iterator>& lhs,
        const ReverseIterator<Iterator>& rhs)
        {
            return(lhs.base() < rhs.base());
        }

        template <class Iterator>
        bool operator<= (const ReverseIterator<Iterator>& lhs,
        const ReverseIterator<Iterator>& rhs)
        {
            return(lhs.base() <= rhs.base());
        }

        template <class Iterator>
        bool operator> (const ReverseIterator<Iterator>& lhs,
        const ReverseIterator<Iterator>& rhs)
        {
            return(lhs.base() > rhs.base());
        }

        template <class Iterator>
        bool operator>= (const ReverseIterator<Iterator>& lhs,
        const ReverseIterator<Iterator>& rhs)
        {
            return(lhs.base() >= rhs.base());
        }
};
#endif