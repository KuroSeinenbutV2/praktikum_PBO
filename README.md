// Use header #include to import library

    example #include <libname>
    <iostream> library is used to load functions like using namespace std, cin, cout, class etc.
    <string> library is used to define variables like nama & jabatam which using alphabet/word

// In class there are 3 atribute variables
   
    public{
        to set attribute of member to be accesed by freely
        }
    private{
        to set attriute of member to be acessed by only parent class
        }
    protected{
        to set attribute of member to be accesed by parent class and derived class
        } 

// to initiate the construct use

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

// To determine "what to do" to attribute, use if else function,

    ecample:
    
    if (jabatan == "teknisi") gajiPokok = 1800000;
        else if (jabatan == "rnd") gajiPokok = 2300000;
        else if (jabatan == "kadiv") gajiPokok = 2700000;
        else gajiPokok = 0;

// To make a Method use 
    
    <datatype> <Method name> (parameter){

        //program code

        return <variable name>
    }

    Example:
    int HitungGaji() {
            return gajiPokok + (lembur * 20000) + (dinas * 400000) + (presensi * 50000);
        }  
