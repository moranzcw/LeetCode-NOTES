class Solution 
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        int width;
        int height;
        
        if( A<E )
        {
            if( C<=E )
            {
                width = 0;
            }
            else
            {
                if( C<=G )
                {
                    width = C-E;    
                }
                else
                {
                    width = G-E;
                }
            }
        }
        else
        {
            if( A<G )
            {
                if( C<=G )
                {
                    width = C-A;
                }
                else
                {
                    width = G-A;
                }
            }
            else
            {
                width = 0;  
            }
        }
        
        if( B<F )
        {
            if( D<=F )
            {
                height = 0;
            }
            else
            {
                if( D<=H )
                {
                    height = D-F;    
                }
                else
                {
                    height = H-F;
                }
            }
        }
        else
        {
            if( B<H )
            {
                if( D<=H )
                {
                    height = D-B;
                }
                else
                {
                    height = H-B;
                }
            }
            else
            {
                height = 0;  
            }
        }
        
        return ( (C-A)*(D-B) + (G-E)*(H-F) ) - width*height;
    }
};