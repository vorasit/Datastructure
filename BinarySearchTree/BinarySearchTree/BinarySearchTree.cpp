        #include "BinarySearchTree.h"
        #include <iostream>

       
        template <class Comparable>
        BinarySearchTree<Comparable>::BinarySearchTree( const Comparable & notFound ) :
          root( NULL ), ITEM_NOT_FOUND( notFound )
        {
        }


        template <class Comparable>
        BinarySearchTree<Comparable>::
        BinarySearchTree( const BinarySearchTree<Comparable> & rhs ) :
          root( NULL ), ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND )
        { 
            *this = rhs;
        }

        template <class Comparable>
        BinarySearchTree<Comparable>::~BinarySearchTree( )
        {
            makeEmpty( );
        }

        /**
         * Insert x into the tree; duplicates are ignored.
         */
        template <class Comparable>
        void BinarySearchTree<Comparable>::insert( const Comparable & x )
        {
            insert( x, root );
        }

        /**
         * Remove x from the tree. Nothing is done if x is not found.
         */
        template <class Comparable>
        void BinarySearchTree<Comparable>::remove( const Comparable & x )
        {
            remove( x, root );
        }


        /**
         * Find the smallest item in the tree.
         * Return smallest item or ITEM_NOT_FOUND if empty.
         */
        template <class Comparable>
        const Comparable & BinarySearchTree<Comparable>::findMin( ) const
        {
            return elementAt( findMin( root ) );
        }

        /**
         * Find the largest item in the tree.
         * Return the largest item of ITEM_NOT_FOUND if empty.
         */
        template <class Comparable>
        const Comparable & BinarySearchTree<Comparable>::findMax( ) const
        {
            return elementAt( findMax( root ) );
        }

        /**
         * Find item x in the tree.
         * Return the matching item or ITEM_NOT_FOUND if not found.
         */
        template <class Comparable>
        const Comparable & BinarySearchTree<Comparable>::
                                 find( const Comparable & x ) const
        {
            return elementAt( find( x, root ) );
        }

        /**
         * Make the tree logically empty.
         */
        template <class Comparable>
        void BinarySearchTree<Comparable>::makeEmpty( )
        {
            makeEmpty( root );
        }

        /**
         * Test if the tree is logically empty.
         * Return true if empty, false otherwise.
         */
        template <class Comparable>
        bool BinarySearchTree<Comparable>::isEmpty( ) const
        {
            return root == NULL;
        }

        /**
         * Print the tree contents in sorted order.
         */
        template <class Comparable>
        void BinarySearchTree<Comparable>::printTree( ) const
        {
            if( isEmpty( ) )
                cout << "Empty tree" << endl;
            else
                printTree( root );
        }

		
		 template <class Comparable>
        void BinarySearchTree<Comparable>::printPre( ) const
        {
            if( isEmpty( ) )
                cout << "Empty tree" << endl;
            else
                printPre( root );
        }
		 template <class Comparable>
        void BinarySearchTree<Comparable>::printIn( ) const
        {
            if( isEmpty( ) )
                cout << "Empty tree" << endl;
            else
                printIn( root );
        }
		 template <class Comparable>
        void BinarySearchTree<Comparable>::printPost( ) const
        {
            if( isEmpty( ) )
                cout << "Empty tree" << endl;
            else
                printPost( root );
        }
		
      
        template <class Comparable>
        const BinarySearchTree<Comparable> &
        BinarySearchTree<Comparable>::
        operator=( const BinarySearchTree<Comparable> & rhs )
        {
            if( this != &rhs )
            {
                makeEmpty( );
                root = clone( rhs.root );
            }
            return *this;
        }

       
        template <class Comparable>
        const Comparable & BinarySearchTree<Comparable>::
        elementAt( BinaryNode<Comparable> *t ) const
        {
            if( t == NULL )
                return ITEM_NOT_FOUND;
            else
                return t->element;
        }

      
        template <class Comparable>
        void BinarySearchTree<Comparable>::
        insert( const Comparable & x, BinaryNode<Comparable> * & t ) const
        {
            if( t == NULL )
                t = new BinaryNode<Comparable>( x, NULL, NULL );
            else if( x < t->element )
                insert( x, t->left );
            else if( t->element < x )
                insert( x, t->right );
            else
                ;  
        }

       
        template <class Comparable>
        void BinarySearchTree<Comparable>::
        remove( const Comparable & x, BinaryNode<Comparable> * & t ) const
        {
            if( t == NULL )
                return;   // Item not found; do nothing
            if( x < t->element )
                remove( x, t->left );
            else if( t->element < x )
                remove( x, t->right );
            else if( t->left != NULL && t->right != NULL ) // Two children
            {
                t->element = findMin( t->right )->element;
                remove( t->element, t->right );
            }
            else
            {
                BinaryNode<Comparable> *oldNode = t;
                t = ( t->left != NULL ) ? t->left : t->right;
                delete oldNode;
            }
        }

      
        template <class Comparable>
        BinaryNode<Comparable> *
        BinarySearchTree<Comparable>::findMin( BinaryNode<Comparable> *t ) const
        {
            if( t == NULL )
                return NULL;
            if( t->left == NULL )
                return t;
            return findMin( t->left );
        }

      
        template <class Comparable>
        BinaryNode<Comparable> *
        BinarySearchTree<Comparable>::findMax( BinaryNode<Comparable> *t ) const
        {
            if( t != NULL )
                while( t->right != NULL )
                    t = t->right;
            return t;
        }

     
        template <class Comparable>
        BinaryNode<Comparable> *
        BinarySearchTree<Comparable>::
        find( const Comparable & x, BinaryNode<Comparable> *t ) const
        {
            if( t == NULL )
                return NULL;
            else if( x < t->element )
                return find( x, t->left );
            else if( t->element < x )
                return find( x, t->right );
            else
                return t;   
        }

        template <class Comparable>
        void BinarySearchTree<Comparable>::
        makeEmpty( BinaryNode<Comparable> * & t ) const
        {
            if( t != NULL )
            {
                makeEmpty( t->left );
                makeEmpty( t->right );
                delete t;
            }
            t = NULL;
        }

       
        template <class Comparable>
        void BinarySearchTree<Comparable>::printTree( BinaryNode<Comparable> *t ) const
        {
            if( t != NULL )
            {
                printTree( t->left );
                cout << t->element << " ";
                printTree( t->right );
            }
        }

		
		 template <class Comparable>
        void BinarySearchTree<Comparable>::printPre( BinaryNode<Comparable> *t ) const
        {
            if( t != NULL )
            {
				cout << t->element << " ";
                printPre( t->left );
                printPre( t->right );
            }
        }
		 template <class Comparable>
        void BinarySearchTree<Comparable>::printIn( BinaryNode<Comparable> *t ) const
        {
            if( t != NULL )
            {
                printIn( t->left );
                cout << t->element << " ";
                printIn( t->right );
            }
        }
		 template <class Comparable>
        void BinarySearchTree<Comparable>::printPost( BinaryNode<Comparable> *t ) const
        {
            if( t != NULL )
            {
                printPost( t->left );
                printPost( t->right );
				cout << t->element << " ";
			}
        }
		
       
        template <class Comparable>
        BinaryNode<Comparable> *
        BinarySearchTree<Comparable>::clone( BinaryNode<Comparable> * t ) const
        {
            if( t == NULL )
                return NULL;
            else
                return new BinaryNode<Comparable>( t->element, clone( t->left ), clone( t->right ) );
        }