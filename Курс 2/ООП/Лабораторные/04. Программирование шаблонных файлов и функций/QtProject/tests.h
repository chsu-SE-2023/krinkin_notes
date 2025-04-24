#ifndef TESTS_H
#define TESTS_H

#endif // TESTS_H

#include "network.h"
#include "net_room.h"

class Tests {
private:
    const double* packets = new double[1]{15.6};
    const int* clients = new int[3]{1, 2, 3};
    const int* address = new int[5]{10, 11, 12, 13, 14};
    const int connected = 3;
    const char* ssid = "CoolWLAN";
    const char* passwd = "qwerty123";
    const bool wpa = false;
    Switch* s_def;
    Switch** s_units;
    Router* r_def;
    Router** r_units;
    constexpr static const char* errors[100] = {
        "PASS",                                            //0
        "FAIL (Switch->connected is not equal)",           //1
        "FAIL (Switch->clients is not equal)",             //2
        "FAIL (Switch->address is not equal)",             //3
        "FAIL (Switch->packets is not equal)",             //4
        "FAIL (Router->connected is not equal)",           //5
        "FAIL (Router->clients is not equal)",             //6
        "FAIL (Router->address is not equal)",             //7
        "FAIL (Router->packets is not equal)",             //8
        "FAIL (Router->ssid is not equal)",                //9
        "FAIL (Router->passwd is not equal)",              //10
        "FAIL (Router->wpa is not equal)",                 //11
        "FAIL (Switch container failed to save object)",   //12
        "FAIL (Router container failed to save object)",   //13
        "FAIL (Switch container failed to find object)",   //14
        "FAIL (Router container failed to find object)",   //15
        "FAIL (Switch container sorting is wrong)",        //16
        "FAIL (Router container sorting is wrong)",        //17
        "FAIL (Operator + is wrong for Switch)",           //18
        "FAIL (Operator -- is wrong for Switch)",          //19
        "FAIL (Operator [] is wrong for Switch)",          //20
        "FAIL (Operator == is wrong for Switch)",          //21
        "FAIL (Operator + is wrong for Router)",           //22
        "FAIL (Operator -- is wrong for Router)",          //23
        "FAIL (Operator [] is wrong for Router)",          //24
        "FAIL (Operator == is wrong for Router)",          //25
    };

public:

    Tests() {
        this->s_def = new Switch(this->packets, this->clients, this->connected, this->address);
        this->s_units = new Switch*[5] {
            new Switch(this->clients, this->connected),
            new Switch(this->address),
            new Switch(this->clients, this->connected, this->address),
            new Switch(this->packets, this->clients, this->connected, this->address),
            new Switch(*s_def)
        };
        this->r_def = new Router(this->packets, this->clients, this->connected, this->address, this->ssid, this->passwd);
        this->r_units = new Router*[3] {
            new Router(this->ssid, this->passwd),
            new Router(*r_def),
            new Router(this->packets, this->clients, this->connected, this->address, this->ssid, this->passwd)
        };
    }

    ~Tests() {
        delete[] this->s_units;
        delete this->s_def;
        delete[] this->r_units;
        delete this->r_def;
    }

    const char* memory() {
        return errors[0];
    }

    const char* data() {
        if (s_units[0]->connected != connected) return errors[1];
        if (*(s_units[0]->clients) != *clients) return errors[2];
        if (*(s_units[1]->address) != *address) return errors[3];
        if (s_units[2]->connected != connected) return errors[1];
        if (*(s_units[2]->clients) != *clients) return errors[2];
        if (*(s_units[2]->address) != *address) return errors[3];
        if (s_units[3]->connected != connected) return errors[1];
        if (*(s_units[3]->clients) != *clients) return errors[2];
        if (*(s_units[3]->address) != *address) return errors[3];
        if (*(s_units[3]->packets) != *packets) return errors[4];
        if (*(s_units[4]->packets) != *(s_def->packets)) return errors[4];
        if (*(s_units[4]->clients) != *(s_def->clients)) return errors[2];
        if (*(s_units[4]->address) != *(s_def->address)) return errors[3];
        if (s_units[4]->connected != s_def->connected) return errors[1];

        if (*(r_units[0]->ssid) != *(ssid)) return errors[9];
        if (*(r_units[0]->passwd) != *(passwd)) return errors[10];
        if (*(r_units[1]->packets) != *packets) return errors[8];
        if (*(r_units[1]->clients) != *clients) return errors[6];
        if (*(r_units[1]->address) != *address) return errors[7];
        if (r_units[1]->connected != connected) return errors[5];
        if (*(r_units[1]->ssid) != *ssid) return errors[8];
        if (*(r_units[1]->passwd) != *passwd) return errors[10];
        if (r_units[1]->wpa != wpa) return errors[11];
        if (*(r_units[2]->packets) != *(r_def->packets)) return errors[8];
        if (*(r_units[2]->clients) != *(r_def->clients)) return errors[6];
        if (*(r_units[2]->address) != *(r_def->address)) return errors[7];
        if (r_units[2]->connected != r_def->connected) return errors[5];
        if (*(r_units[2]->ssid) != *(r_def->ssid)) return errors[9];
        if (*(r_units[2]->passwd) != *(r_def->passwd)) return errors[10];
        if (r_units[2]->wpa != r_def->wpa) return errors[11];
        return errors[0];
    }

    const char* container() {
        ServerRoom<Switch> s_cont = ServerRoom<Switch>();
        for (int i=0; i<5; i++)
            s_cont = s_cont + *s_units[i];

        for (int i=0; i<5; i++)
            if (s_cont.get_shelf(&s_cont, i)->device != s_units[i])
                return errors[12];

        ServerRoom<Router> r_cont = ServerRoom<Router>();
        for (int i=0; i<5; i++)
            r_cont = r_cont + *r_units[i];

        for (int i=0; i<5; i++)
            if (r_cont.get_shelf(&r_cont, i)->device != r_units[i])
                return errors[13];

        return errors[0];
    }

    const char* search() {

        ServerRoom<Switch> s_cont = ServerRoom<Switch>();
        for (int i=0; i<5; i++)
            s_cont = s_cont + *s_units[i];
        const Switch* sw = s_cont.search(this->address);
        if (sw != s_units[1]) return errors[14];

        ServerRoom<Router> r_cont = ServerRoom<Router>();
        for (int i=0; i<5; i++)
            r_cont = r_cont + *r_units[i];
        const Router* rt = r_cont.search(this->address);
        if (rt != r_units[1]) return errors[15];

        return errors[0];
    }

    const char* sort() {
        Switch** ls_units = new Switch*[3] {
            new Switch(new int[3] {1, 2, 3}, 3),
            new Switch(new int[4] {1, 2, 3, 4}, 4),
            new Switch(new int[5] {1, 2, 3, 4, 5}, 5)
        };
        ServerRoom<Switch> s_cont = ServerRoom<Switch>();
        for (int i=0; i<3; i++)
            s_cont = s_cont + *ls_units[i];
        s_cont.sort();
        if (s_cont.first->device->connected != 3 || s_cont.last->device->connected != 5)
            return errors[16];

        Router** lr_units = new Router*[3] {
            new Router(this->packets, new int[3] {1, 2, 3}, 3, this->address, this->ssid, this->passwd),
            new Router(this->packets, new int[4] {1, 2, 3, 4}, 4, this->address, this->ssid, this->passwd),
            new Router(this->packets, new int[5] {1, 2, 3, 4, 5}, 5, this->address, this->ssid, this->passwd)
        };
        ServerRoom<Router> r_cont = ServerRoom<Router>();
        for (int i=0; i<3; i++)
            r_cont = r_cont + *lr_units[i];
        r_cont.sort();
        if (r_cont.first->device->connected != 3 || r_cont.last->device->connected != 5)
            return errors[17];

        return errors[0];
    };

    const char* opers() {
        Switch* sw = new Switch();
        ServerRoom<Switch> c_sw = ServerRoom<Switch>();
        c_sw = c_sw + *sw;
        if (c_sw.first->device != sw) return errors[18];
        c_sw--;
        if (c_sw.first != nullptr) return errors[19];
        ServerRoom<Switch> s_cont = ServerRoom<Switch>();
        for (int i = 0; i < 3; i++)
            s_cont = s_cont + *s_units[i];
        if (s_cont[2] != s_units[2]) return errors[20];
        ServerRoom<Switch> s_cont_1 = ServerRoom<Switch>();
        for (int i = 0; i < 3; i++)
            s_cont_1 = s_cont_1 + *s_units[i];
        ServerRoom<Switch> s_cont_2 = ServerRoom<Switch>();
        for (int i = 0; i < 3; i++)
            s_cont_2 = s_cont_2 + *s_units[i];
        if (!(s_cont_1 == s_cont_2)) return errors[21];

        Router* rt = new Router();
        ServerRoom<Router> c_rt = ServerRoom<Router>();
        c_rt = c_rt + *rt;
        if (c_rt.first->device != rt) return errors[18];
        c_rt--;
        if (c_rt.first != nullptr) return errors[19];
        ServerRoom<Router> r_cont = ServerRoom<Router>();
        for (int i = 0; i < 3; i++)
            r_cont = r_cont + *r_units[i];
        if (r_cont[2] != r_units[2]) return errors[20];
        ServerRoom<Router> r_cont_1 = ServerRoom<Router>();
        for (int i = 0; i < 3; i++)
            r_cont_1 = r_cont_1 + *r_units[i];
        ServerRoom<Router> r_cont_2 = ServerRoom<Router>();
        for (int i = 0; i < 3; i++)
            r_cont_2 = r_cont_2 + *r_units[i];
        if (!(r_cont_2 == r_cont_2)) return errors[21];

        return errors[0];
    }
};
