// Use header #include to import library

    example #include <libname>
    <iostream> library is used to load functions like using namespace std, cin, cout, class etc.
    <string> library is used to define variables like nama & jabatam which using alphabet/word

// Class
    <br> Class is a blueprint for creating object.
    
    In class there are 3 atribute variables
   
    public:
        to set attribute of member to be accesed by freely
    
    private:
        to set attriute of member to be acessed by only parent class
        
    protected:
        to set attribute of member to be accesed by parent class and derived class

    Example:
    class Karyawan {
    private:
    string nama;
    string jabatan;
    int lembur;
    int dinas;
    int presensi;
    int gajiPokok;
    }

//  Object
    <br>Object are components that created from Class

    Example:
    {
        Karyawan karyawan(nama, jabatan, lembur, dinas, presensi);
    }

//  Constructor is a special member function of a class that is automatically called when an object of that class is created.

to initiate the construct use:

    this->(construct name)=(attribute name)
    example
    class Karyawan {
    public:
    Karyawan(string nama, string jabatan, int lembur, int dinas, int presensi) {
        this->nama = nama;
        this->jabatan = jabatan;
        this->lembur = lembur;
        this->dinas = dinas;
        this->presensi = presensi;
        }
    }

//  To determine "what to do" to attribute, use if else function,

    ecample:
    
    if (jabatan == "teknisi") gajiPokok = 1800000;
        else if (jabatan == "rnd") gajiPokok = 2300000;
        else if (jabatan == "kadiv") gajiPokok = 2700000;
        else gajiPokok = 0;

//  Method
    <br> Method is a program function that is defined within a class.
    
    To make a Method use:
    <datatype> <Method name> (parameter){

        //program code

        return <variable name>
    }

    Example:
    int HitungGaji() {
            return gajiPokok + (lembur * 20000) + (dinas * 400000) + (presensi * 50000);
        }  

//  Encapsulation
    <br>Encapsulation restricts direct access to class components, this mean it can hide the member of class.

    Example:
    class Karyawan {
    private:
    string nama;
    string jabatan;
    int lembur;
    int dinas;
    int presensi;
    int gajiPokok;
    }
