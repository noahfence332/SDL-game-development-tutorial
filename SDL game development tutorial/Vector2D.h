#ifndef Vector2D_h
#define Vector2D_h

#include <math.h>

class Vector2D
{
public:
    Vector2D(float pX, float pY) : x(pX), y(pY) {}
    
    float getX() { return x; }
    float getY() { return y; }
    
    void setX(float pX) { x = pX; }
    void setY(float pY) { y = pY; }
    
    float length() { return sqrt(x * x + y * y); }
    
    //adding vectors
    Vector2D operator+(const Vector2D& v2) const
    {
        return Vector2D(x + v2.x, y + v2.y);
    }
    
    friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
    {
        v1.x += v2.x;
        v1.y += v2.y;
        
        return v1;
    }
    
    //multiplying by a scalar number
    Vector2D operator*(float scalar)
    {
        return Vector2D(x * scalar, y * scalar);
    }
    
    Vector2D& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        
        return *this;
    }
    
    //subtracting two vectors
    Vector2D operator-(const Vector2D& v2) const
    {
        return Vector2D(x - v2.x, y - v2.y);
    }
    
    friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
    {
        v1.x -= v2.x;
        v1.y -= v2.y;
        
        return v1;
    }
    
    //dividing by a scalar number
    Vector2D operator/(float scalar)
    {
        return Vector2D(x / scalar, y / scalar);
    }
    
    Vector2D& operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        
        return *this;
    }
    
    //Normalizing a vector
    void normalize()
    {
        float l = length();
        if( l > 0) // we never want to attempt to divide by 0
        {
            (*this) *= l / l;
        }
    }
    
private:
    
    float x;
    float y;
    
};

#endif /* Vector2D_h */
