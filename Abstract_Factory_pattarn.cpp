#include <iostream>
#include <string>
using namespace std;

// Abstract Products
class IDumb {
public:
    virtual string Name() = 0;
    virtual ~IDumb() {}
};

class ISmart {
public:
    virtual string Name() = 0;
    virtual ~ISmart() {}
};

// Concrete Dumb Phones
class Asha : public IDumb {
public:
    string Name() override { return "Asha"; }
};

class Primo : public IDumb {
public:
    string Name() override { return "Guru"; }
};

class Genie : public IDumb {
public:
    string Name() override { return "Genie"; }
};

// Concrete Smart Phones
class Lumia : public ISmart {
public:
    string Name() override { return "Lumia"; }
};

class GalaxyS2 : public ISmart {
public:
    string Name() override { return "GalaxyS2"; }
};

class Titan : public ISmart {
public:
    string Name() override { return "Titan"; }
};

// Abstract Factory
class IPhoneFactory {
public:
    virtual ISmart* GetSmart() = 0;
    virtual IDumb* GetDumb() = 0;
    virtual ~IPhoneFactory() {}
};

// Concrete Factories
class SamsungFactory : public IPhoneFactory {
public:
    ISmart* GetSmart() override {
        return new GalaxyS2();
    }
    IDumb* GetDumb() override {
        return new Primo();
    }
};

class HTCFactory : public IPhoneFactory {
public:
    ISmart* GetSmart() override {
        return new Titan();
    }
    IDumb* GetDumb() override {
        return new Genie();
    }
};

class NokiaFactory : public IPhoneFactory {
public:
    ISmart* GetSmart() override {
        return new Lumia();
    }
    IDumb* GetDumb() override {
        return new Asha();
    }
};

// Enum to select manufacturer
enum MANUFACTURERS {
    SAMSUNG,
    HTC,
    NOKIA
};

// Phone Type Checker (Client)
class PhoneTypeChecker {
private:
    IPhoneFactory* factory;
    MANUFACTURERS manu;

public:
    PhoneTypeChecker(MANUFACTURERS m) {
        manu = m;
    }

    void CheckProducts() {
        switch (manu) {
            case SAMSUNG:
                factory = new SamsungFactory();
                break;
            case HTC:
                factory = new HTCFactory();
                break;
            case NOKIA:
                factory = new NokiaFactory();
                break;
        }

        ISmart* smart = factory->GetSmart();
        IDumb* dumb = factory->GetDumb();

        cout << "\n" << ManufacturerToString(manu) << ":\nSmart Phone: "
             << smart->Name() << "\nDumb Phone: " << dumb->Name() << endl;

        delete smart;
        delete dumb;
        delete factory;
    }

    string ManufacturerToString(MANUFACTURERS m) {
        switch (m) {
            case SAMSUNG: return "SAMSUNG";
            case HTC: return "HTC";
            case NOKIA: return "NOKIA";
            default: return "UNKNOWN";
        }
    }
};

// Main function
int main() {
    PhoneTypeChecker checker(SAMSUNG);
    checker.CheckProducts();

    checker = PhoneTypeChecker(HTC);
    checker.CheckProducts();

    checker = PhoneTypeChecker(NOKIA);
    checker.CheckProducts();

    return 0;
}

