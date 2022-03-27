//
//  VecLib
//
// A custom linear algebra library to
// speed up machine learning and graphics.
//
//  Created by Nicholas Pakaluk on 7/5/21.
//

#ifndef math_h
#define math_h

// TODO: compy constructors

// 2D vector structure
struct vec2 {
    double x, y;
    
    // constructor
    vec2(double X = 0.0, double Y = 0.0){
        x = X;
        y = Y;
    }
    
    // vector addition and incrementing
    vec2 operator + (vec2 v){
        return vec2(x + v.x, y + v.y);
    }
    void operator += (vec2 v){
        x += v.x;
        y += v.y;
    }
    vec2 operator ++ (){
        x += 1.0;
        y += 1.0;
        return vec2(x, y);
    }
    vec2 operator ++ (int){
        vec2 m = vec2(x, y);
        x += 1.0;
        y += 1.0;
        return m;
    }
    
    // vector subtraction and decrementing
    vec2 operator - (vec2 v){
        return vec2(x - v.x, y - v.y);
    }
    void operator -= (vec2 v){
        x -= v.x;
        y -= v.y;
    }
    vec2 operator -- (){
        x -= 1.0;
        y -= 1.0;
        return vec2(x, y);
    }
    vec2 operator -- (int){
        vec2 m = vec2(x, y);
        x -= 1.0;
        y -= 1.0;
        return m;
    }
    
    // dot product
    double operator * (vec2 v){
        return x * v.x + y * v.y;
    }
    
    // scaling
    vec2 operator * (double s){
        return vec2(s * x, s * y);
    }
    void operator *= (double s){
        x *= s;
        y *= s;
    }
    vec2 operator / (double s){
        return vec2(x / s, y / s);
    }
    void operator /= (double s){
        x /= s;
        y /= s;
    }
    
    // assignment
    void operator = (vec2 v){
        x = v.x;
        y = v.y;
    }
    
    // equality
    bool operator == (vec2 v){
        return x == v.x && y == v.y;
    }
    
    // magnitude
    double mag(){
        return std::sqrt(x * x + y * y);
    }
    
    // normalization
    void norm(){
        double m = 1 / std::sqrt(x * x + y * y);
        x *= m;
        y *= m;
    }
    
    // reflection
    vec2 reflect(vec2 v, vec2 n){
        return v - n * (v * n * 2.0);
    }
    
    // print
    void print(){
        std::cout << x << ", " << y << std::endl;
    }
};

// 3D vector structure
struct vec3 {
    double x, y, z;
    
    // constructor
    vec3(double X = 0.0, double Y = 0.0, double Z = 0.0){
        x = X;
        y = Y;
        z = Z;
    }
    
    // vector addition and incrementing
    vec3 operator + (vec3 v){
        return vec3(x + v.x, y + v.y, z + v.z);
    }
    void operator += (vec3 v){
        x += v.x;
        y += v.y;
        z += v.z;
    }
    vec3 operator ++ (){
        x += 1.0;
        y += 1.0;
        z += 1.0;
        return vec3(x, y, z);
    }
    vec3 operator ++ (int){
        vec3 m = vec3(x, y, z);
        x += 1.0;
        y += 1.0;
        z += 1.0;
        return m;
    }
    
    // vector subtraction and decrementing
    vec3 operator - (vec3 v){
        return vec3(x - v.x, y - v.y, z - v.z);
    }
    void operator -= (vec3 v){
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }
    vec3 operator -- (){
        x -= 1.0;
        y -= 1.0;
        z -= 1.0;
        return vec3(x, y, z);
    }
    vec3 operator -- (int){
        vec3 m = vec3(x, y, z);
        x -= 1.0;
        y -= 1.0;
        z -= 1.0;
        return m;
    }
    
    // dot product
    double operator * (vec3 v){
        return x * v.x + y * v.y + z * v.z;
    }
    
    // scaling
    vec3 operator * (double s){
        return vec3(s * x, s * y, s * z);
    }
    void operator *= (double s){
        x *= s;
        y *= s;
        z *= s;
    }
    vec3 operator / (double s){
        return vec3(x / s, y / s, z / s);
    }
    void operator /= (double s){
        x /= s;
        y /= s;
        z /= s;
    }
    
    // assignment
    void operator = (vec3 v){
        x = v.x;
        y = v.y;
        z = v.z;
    }
    
    // equality
    bool operator == (vec3 v){
        return x == v.x && y == v.y && z == v.z;
    }
    
    // magnitude
    double mag(){
        return std::sqrt(x * x + y * y + z * z);
    }
    
    // normalization
    void norm(){
        double m = 1 / std::sqrt(x * x + y * y + z * z);
        x *= m;
        y *= m;
        z *= m;
    }
    
    // reflection
    vec3 reflect(vec3 v, vec3 n){
        return v - n * (v * n * 2.0);
    }
    
    // cross product
    vec3 operator ^ (vec3 v){
        return vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }
    vec3 cross(vec3 v){
        return vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }
    
    // print
    void print(){
        std::cout << x << ", " << y << ", " << z << std::endl;
    }
};

// 4D vector structure
struct vec4 {
    double x, y, z, w;
    
    // constructor
    vec4(double X = 0.0, double Y = 0.0, double Z = 0.0, double W = 0.0){
        x = X;
        y = Y;
        z = Z;
        w = W;
    }
    
    // vector addition and incrementing
    vec4 operator + (vec4 v){
        return vec4(x + v.x, y + v.y, z + v.z, w + v.w);
    }
    void operator += (vec4 v){
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
    }
    vec4 operator ++ (){
        x += 1.0;
        y += 1.0;
        z += 1.0;
        w += 1.0;
        return vec4(x, y, z, w);
    }
    vec4 operator ++ (int){
        vec4 m = vec4(x, y, z, w);
        x += 1.0;
        y += 1.0;
        z += 1.0;
        w += 1.0;
        return m;
    }
    
    // vector subtraction and decrementing
    vec4 operator - (vec4 v){
        return vec4(x - v.x, y - v.y, z - v.z, w - v.w);
    }
    void operator -= (vec4 v){
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
    }
    vec4 operator -- (){
        x -= 1.0;
        y -= 1.0;
        z -= 1.0;
        w -= 1.0;
        return vec4(x, y, z, w);
    }
    vec4 operator -- (int){
        vec4 m = vec4(x, y, z, w);
        x -= 1.0;
        y -= 1.0;
        z -= 1.0;
        w -= 1.0;
        return m;
    }
    
    // dot product
    double operator * (vec4 v){
        return x * v.x + y * v.y + z * v.z + w * v.w;
    }
    
    // scaling
    vec4 operator * (double s){
        return vec4(s * x, s * y, s * z, s * w);
    }
    void operator *= (double s){
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    vec4 operator / (double s){
        return vec4(x / s, y / s, z / s, w / s);
    }
    void operator /= (double s){
        x /= s;
        y /= s;
        z /= s;
        w /= s;
    }
    
    // assignment
    void operator = (vec4 v){
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
    }
    
    // equality
    bool operator == (vec4 v){
        return x == v.x && y == v.y && z == v.z && w == v.w;
    }
    
    // magnitude
    double mag(){
        return std::sqrt(x * x + y * y + z * z + w * w);
    }
    
    // normalization
    void norm(){
        double m = 1 / std::sqrt(x * x + y * y + z * z + w * w);
        x *= m;
        y *= m;
        z *= m;
        w *= m;
    }
    
    // reflection
    vec4 reflect(vec4 v, vec4 n){
        return v - n * (v * n * 2.0);
    }
    
    // print
    void print(){
        std::cout << x << ", " << y << ", " << z << ", " << w << std::endl;
    }
};

// 2 x 2 matrix structure TODO: rotation, scaling
struct mat2 {
    vec2 x, y;
    
    // constructor
    mat2(vec2 X = vec2(1.0, 0.0), vec2 Y = vec2(0.0, 1.0)){
        x = X;
        y = Y;
    }
    
    // linear transformation
    vec2 operator * (vec2 v){
        return vec2(x * v, y * v);
    }
    
    // matrix multiplication
    mat2 operator * (mat2 m){
        return mat2(m * x, m * y);
    }
    
    // rotation matrix
    mat2 rotation(double d){
        double s = std::sin(d), c = std::cos(d);
        return mat2(vec2(s, c), vec2(c, -s));
    }
    
    // rotate this matrix
    void rotate(double d){
        //mat3 m = mat3.rotation(dx, dy, dz); TODO: figure this out
    }
    
    void print(){
        x.print();
        y.print();
    }
};

// 3 x 3 matrix structure TODO: rotation, scaling
struct mat3 {
    vec3 x, y, z;
    
    // constructor
    mat3(vec3 X = vec3(1.0, 0.0, 0.0), vec3 Y = vec3(0.0, 1.0, 0.0), vec3 Z = vec3(0.0, 0.0, 1.0)){
        x = X;
        y = Y;
        z = Z;
    }
    
    // linear transformation
    vec3 operator * (vec3 v){
        return vec3(x * v, y * v, z * v);
    }
    
    // matrix multiplication
    mat3 operator * (mat3 m){
        return mat3(m * x, m * y, m * z);
    }
    
    // rotation matrix
    mat3 rotation(double dx, double dy, double dz){
        double sx = std::sin(dx), cx = std::cos(dx), sy = std::sin(dy), cy = std::cos(dy), sz = std::sin(dz), cz = std::cos(dz);
        return mat3(vec3(cz * cy, sz * cy, -sy),
                    vec3(cz * sy * sx - sz * cx, sz * sy * sx + cz * cx, cy * sx),
                    vec3(cz * sy * cx + sz * sx, sz * sy * cx - cz * sx, cy * cx));
    }
    
    // rotate this matrix
    void rotate(double dx, double dy, double dz){
        //mat3 m = mat3.rotation(dx, dy, dz); TODO: figure this out
    }
    
    void print(){
        x.print();
        y.print();
        z.print();
    }
};

// 4 x 4 matrix structure TODO: all
struct mat4 {
    vec4 x, y, z, w;
    
    // constructor
    mat4(vec4 X = vec4(1.0, 0.0, 0.0, 0.0), vec4 Y = vec4(0.0, 1.0, 0.0, 0.0), vec4 Z = vec4(0.0, 0.0, 1.0, 0.0), vec4 W = vec4(0.0, 0.0, 0.0, 1.0)){
        x = X;
        y = Y;
        z = Z;
        w = W;
    }
    
    // linear transformation
    vec4 operator * (vec4 v){
        return vec4(x * v, y * v, z * v, w * v);
    }
    
    // matrix multiplication
    mat4 operator * (mat4 m){
        return mat4(m * x, m * y, m * z, m * w);
    }
};

// TODO: outsider functions: matrix rotation, vector-scalar multiplication, linear transformation, vactor: [round, floor]

// 2D linear transformations
vec2 operator * (vec2 v, mat2 m){
    return vec2(m.x * v, m.y * v);
}
vec2 operator * (mat2 m, vec2 v){
    return vec2(m.x * v, m.y * v);
}
//void vec2::rotate(double t){
    
//}

// 3D linear transformations
vec3 operator * (vec3 v, mat3 m){
    return vec3(m.x * v, m.y * v, m.z * v);
}
vec3 operator * (mat3 m, vec3 v){
    return vec3(m.x * v, m.y * v, m.z * v);
}

// vector absolute value functions
vec2 abs(vec2 v){
    return vec2(std::abs(v.x), std::abs(v.y));
}
vec3 abs(vec3 v){
    return vec3(std::abs(v.x), std::abs(v.y), std::abs(v.z));
}
vec4 abs(vec4 v){
    return vec4(std::abs(v.x), std::abs(v.y), std::abs(v.z), std::abs(v.w));
}

// vector minimum functions
vec2 min(vec2 a, vec2 b){
    return vec2(std::min(a.x, b.x), std::min(a.y, b.y));
}
vec3 min(vec3 a, vec3 b){
    return vec3(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z));
}
vec4 min(vec4 a, vec4 b){
    return vec4(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z), std::min(a.w, b.w));
}

// vector maximum functions
vec2 max(vec2 a, vec2 b){
    return vec2(std::max(a.x, b.x), std::max(a.y, b.y));
}
vec3 max(vec3 a, vec3 b){
    return vec3(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z));
}
vec4 max(vec4 a, vec4 b){
    return vec4(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z), std::max(a.w, b.w));
}

// color
int color(int r = 0x0, int g = 0x0, int b = 0x0, int a = 0xff){
    return a << 24 | r << 16 | g << 8 | b;
}

// complex number structure TODO: exponentiation, modulus,
struct complex {
    double r, i;
    
    // constructor
    complex(double R = 0.0, double I = 1.0){
        r = R;
        i = I;
    }
    
    // assignment
    void operator = (complex c){
        r = c.r;
        i = c.i;
    }
    
    // complex addition
    complex operator + (complex c){
        return complex(r + c.r, i + c.i);
    }
    void operator += (complex c){
        r += c.r;
        i += c.i;
    }
    
    // complex subtraction
    complex operator - (complex c){
        return complex(r - c.r, i - c.i);
    }
    void operator -= (complex c){
        r -= c.i;
        r -= c.i;
    }
    
    // comlex multiplication
    complex operator * (complex c){
        return complex(r * c.r - i * c.i, r * c.i + i * c.r);
    }
    void operator *= (complex c){
        double t = r;
        r = r * c.r - i * c.i;
        i = t * c.i + i * c.r;
    }
    
    // complex division
    complex operator / (complex c){
        double m = 1 / (c.r * c.r + c.i * c.i);
        return complex((r * c.r + i * c.i) * m, (i * c.r - r * c.i) * m);
    }
    void operator /= (complex c){
        double m = 1 / (c.r * c.r + c.i * c.i), t = r;
        r = (r * c.r + i * c.i) * m;
        i = (i * c.r - t * c.i) * m;
    }
    
    // simple exponentiation
    complex operator ^ (int n){
        complex c = complex(1.0, 0.0);
        for(; n > 0; n--)
            c *= complex(r, i);
        return c;
    }
    
    // complex exponentiation
    complex exp(complex c){
        return complex(); // TODO: look up formula, finish
    }
    
    // print
    void print(){
        std::cout << r << ", " << i << std::endl;
    }
};

// quaternion structure TODO: rotation, multiplication
struct quaternion {
    double r, i, j, k;
    
    // constructor
    quaternion(double R = 0.0, double I = 0.0, double J = 0.0, double K = 0.0){
        r = R;
        i = I;
        j = J;
        k = K;
    }
    
    // addition
    quaternion operator + (quaternion q){
        return quaternion(r + q.r, i + q.i, j + q.j, k + q.k);
    }
    void operator += (quaternion q){
        r += q.r;
        i += q.i;
        j += q.j;
        k += q.k;
    }
    
    // subtraction
    quaternion operator - (quaternion q){
        return quaternion(r - q.r, i - q.i, j - q.j, k - q.k);
    }
    void operator -= (quaternion q){
        r -= q.r;
        i -= q.i;
        j -= q.j;
        k -= q.k;
    }
    
    // multiplication
    quaternion operator * (quaternion q){
        return quaternion();
    }
    
    // TODO: finish multiplication, division(?), exponentiation(?)
    
};

// ray structure
struct ray {
    vec3 o, d;
    double t;
    
    // constructor
    ray(vec3 O = vec3(), vec3 D = vec3(), double T = 1.0){
        o = O;
        d = D;
        t = T;
    }
    
    // ray marching
    void march(double (*sdf) (vec3), double err, int max){
        double m;
        do{
            m = sdf(o + d * t);
            t += m;
        }
        while(m > err && max-- > 0);
    }
    
    // ray tracing
    void trace(double (*intersect) (ray)){
        t = intersect(ray(o, d, t));
    }
    
    // ray casting - when I need it - for Minecraft
};

// shape class TODO: all
class shape {
    // TODO: create virtual/abstract class with SDFs, intersections, normals, colors, etc...
private:
    mat3 orientation;
    vec3 position, velocity, acceleration;
    
public:
    //double virtual sdf(vec3 v){}
    //double virtual intersect(ray r){}
    
};

// shape sub classes
class sphere : public shape {
    
};

// camera class TODO: projection (?), movement (?), ray stuff
class camera {
private:
    mat3 direction;
    double focal_length;
    vec3 position, velocity, acceleration;
    
    // camera constructor
    camera (vec3 pos = vec3(), mat3 dir = mat3(), double FL = 1) {
        position = pos;
        velocity = vec3();
        acceleration = vec3();
        direction = dir;
        focal_length = FL;
    }
};

// generalized vector TODO: dot product, constructor / destructor
template <typename T>
class vector{

private:
    int length;
    T * elements = nullptr;
    
public:
    // 'structors
    vector<T> (int l = 1) {
        length = l;
        elements = new T[l];
        std::cout << "why" << std::endl;
    }
    vector<T> (const vector<T> & v){
        length = v.length;
        elements = new T[length];
        for(int i = 0; i < length; i++)
            elements[i] = v.elements[i];
        std::cout << "what how?" << std::endl;
    }
    ~vector<T> () {
        delete [] elements;
        std::cout << "oh cool" << std::endl;
    }
    
    // get length
    int len () {
        return length;
    }
    
    // read and write element
    T & operator [] (int i) {
        return elements[i];
    }
    
    // copy assignment
    vector<T> operator = (vector<T> v) {
        delete [] elements;
        length = v.len();
        elements = new T[length];
        for(int i = 0; i < length; i++)
            elements[i] = v[i];
        return * this;
    }
    
    // vector addition
    vector<T> operator + (vector<T> v) {
        vector<T> t (std::min(length, v.len()));
        for(int i = 0; i < t.len(); i++){
            t[i] = elements[i] + v[i];
        }
        return t;
    }
    void operator += (vector<T> v) {
        for(int i = 0; i < length; i++){
            elements[i] += v[i];
        }
    }
    
    // vector subtraction
    vector<T> operator - (vector<T> v) {
        vector<T> t(std::min(length, v.len()));
        for(int i = 0; i < t.len(); i++){
            t[i] = elements[i] - v[i];
        }
        return t;
    }
    void operator -= (vector<T> v) {
        for(int i = 0; i < length; i++){
            elements[i] -= v[i];
        }
    }
    
    // vector hadamard product
    vector<T> operator * (vector<T> v) {
        vector<T> t(std::min(length, v.len()));
        for(int i = 0; i < t.len(); i++){
            t[i] = elements[i] * v[i];
        }
        return t;
    }
    void operator *= (vector<T> v) {
        for(int i = 0; i < length; i++){
            elements[i] *= v[i];
        }
    }
    
    // vector dot product
    T operator & (vector<T> v) {
        T t = 0;
        int m = std::min(length, v.len());
        for(int i = 0; i < m; i++)
            t += elements[i] * v[i];
        return t;
    }
    
    // reserve space
    void reserve (int l) {
        length = l;
        T * t = new T[length];
        for(int i = 0; i < length; i++)
            t[i] = elements[i];
        delete [] elements;
        elements = t;
    }
    
    // push element
    void push (T element) {
        T * t = new T[length + 1];
        for(int i = 0; i < length; i++)
            t[i] = elements[i];
        t[length] = element;
        delete [] elements;
        elements = t;
        length++;
    }
    
    // pop element
    T pop () {
        length--;
        T * t = new T[length];
        for(int i = 0; i < length; i++)
            t[i] = elements[i];
        T m = elements[length];
        delete [] elements;
        elements = t;
        return m;
    }
    
    // print
    void print () {
        std::cout << "[";
        for(int i = 0; i < length; i++){
            if(i == length - 1){
                std::cout << elements[i] << "]" << std::endl;
                break;
            }
            std::cout << elements[i] << ", ";
        }
    }
};

// generalized matrix TODO: all

// generalized tensor TODO: all

#endif /* math_h */
