#include "pch.h"
#include "CppUnitTest.h"
#include "../QtProject/src/repeater.h"
#include "../QtProject/src/wl_repeater.h"
#include "../QtProject/src/switch.h"
#include "../QtProject/src/gateway.h"
#include "../QtProject/src/router.h"
#include "../QtProject/src/net_room.h"
#include "../QtProject/src/stats.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Classes
{
	TEST_CLASS(MAllocTest)
	{
	public:
		/*
		* ¬ тестируемых методах провер€етс€ работают ли
		* конструкторы и деструкторы (выделение и очистка пам€ти)
		*/
		TEST_METHOD(WLRepeaterAlloc)
		{
			WLRepeater* wl_rep = new WLRepeater();
			delete wl_rep;
		}

		TEST_METHOD(SwitchAlloc)
		{
			Switch* sw = new Switch();
			delete sw;
		}

		TEST_METHOD(GatewayAlloc)
		{
			Gateway* gw = new Gateway();
			delete gw;
		}

		TEST_METHOD(RouterAlloc)
		{
			Router* r = new Router();
			delete r;
		}

		TEST_METHOD(ServerRoomAlloc)
		{
			Router* r = new Router();
			ServerRoom<Router>* sr = new ServerRoom<Router>(*r);
			delete sr;
			delete r;
		}
	};

	TEST_CLASS(DataTest)
	{
	public:

		/*
		* ¬ тестируемых методах провер€етс€ правильно ли
		* в объектах классов сохран€ютс€ данные
		*/

		TEST_METHOD(RepeaterData)
		{
			const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
			std::array<int, 5> address = { 10, 11, 12, 13, 14 };
			Repeater rep(packets, address);
			for (int i = 0; i < 5; i++)
				Assert::AreEqual(rep.get_address()[i], address[i]);
			Assert::AreEqual(rep.get_packets(), packets);
		}

		TEST_METHOD(WLRepeaterData)
		{
			const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
			std::array<int, 5> address = { 10, 11, 12, 13, 14 };
			std::string ssid = "CoolWLAN";
			std::string passwd = "qwerty123";
			WLRepeater wl_rep(packets, address, ssid, passwd);
			for (int i = 0; i < 5; i++)
				Assert::AreEqual(wl_rep.get_address()[i], address[i]);
			Assert::AreEqual(wl_rep.get_packets(), packets);
			Assert::AreEqual(wl_rep.get_ssid(), ssid);
		}

		TEST_METHOD(SwitchData)
		{
			const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
			std::array<int, 32> clients = { 1, 2, 3 };
			std::array<int, 5> address = { 10, 11, 12, 13, 14 };
			Switch sw(packets, clients, address);
			for (int i = 0; i < 5; i++)
				Assert::AreEqual(sw.get_address()[i], address[i]);
			Assert::AreEqual(sw.get_packets(), packets);
			for (int i = 0; i < clients.size(); i++)
				Assert::AreEqual(sw.get_clients()[i], clients[i]);
		}

		TEST_METHOD(GatewayData)
		{
			const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
			std::array<int, 32> clients = { 1, 2, 3 };
			std::array<int, 5> address = { 10, 11, 12, 13, 14 };
			std::string protocol = "sftp://";
			Gateway gw(packets, clients, address, protocol);
			for (int i = 0; i < 5; i++)
				Assert::AreEqual(gw.get_address()[i], address[i]);
			Assert::AreEqual(gw.get_packets(), packets);
			if (gw.get_clients() != clients) Assert::Fail(L"Clients are not the same");
			Assert::AreEqual(gw.get_protocol(), protocol);
		}

		TEST_METHOD(RouterData)
		{
			const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
			std::array<int, 32> clients = { 1, 2, 3 };
			std::array<int, 5> address = { 10, 11, 12, 13, 14 };
			std::string protocol = "sftp://";
			std::string ssid = "CoolWLAN";
			std::string passwd = "qwerty123";
			Router r(packets, clients, address, protocol, ssid, passwd);
			for (int i = 0; i < 5; i++)
				Assert::AreEqual(r.get_address()[i], address[i]);
			Assert::AreEqual(r.get_packets(), packets);
			std::array<int, 32> test = r.get_clients();
			if (test != clients) Assert::Fail(L"Clients are not the same");
			Assert::AreEqual(r.get_protocol(), protocol);
			Assert::AreEqual(r.get_ssid(), ssid);
		}

		TEST_METHOD(ServerRoomData)
		{
			const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
			std::array<int, 32> clients = { 1, 2, 3 };
			std::array<int, 5> address = { 10, 11, 12, 13, 14 };
			std::string protocol = "sftp://";
			std::string ssid = "CoolWLAN";
			std::string passwd = "qwerty123";
			Router r(packets, clients, address, protocol, ssid, passwd);
			ServerRoom<Router> sr(r);
			const Router** out = sr.get_array();
			for (int i = 0; i < 5; i++)
				Assert::AreEqual(out[0]->get_address()[i], address[i]);
			Assert::AreEqual(out[0]->get_packets(), packets);
			if (out[0]->get_clients() != clients) Assert::Fail(L"Clients are not the same");
			Assert::AreEqual(out[0]->get_protocol(), protocol);
			Assert::AreEqual(out[0]->get_ssid(), ssid);
		}
	};

	TEST_CLASS(StatsTest) {
	public:

		/*
		* ¬ тестируемых методах производитс€ проверка
		* работы класса Stats
		*/

		TEST_METHOD(RouterObj) {
			const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
			std::array<int, 32> clients = { 1, 2, 3 };
			std::array<int, 5> address = { 10, 11, 12, 13, 14 };
			std::string ssid = "CoolWLAN";
			std::string passwd = "qwerty123";
			std::string protocol = "sftp://";
			Router* r_def = new Router(packets, clients, address, protocol, ssid, passwd);
			Router** r_units = new Router * [3] {
				new Router(ssid, passwd),
					new Router(*r_def),
					new Router(packets, clients, address, protocol, ssid, passwd)
				};
			Stats* stats = new Stats();
			ServerRoom<Router>* room = new ServerRoom<Router>();
			for (int i = 0; i < 3; i++) {
				room->add(*r_units[i]);
			}
			stats->to_map(room, 3, 2, true);
			Assert::AreNotEqual(stats->get_total_devices(), 0);
			stats->clear();
			Assert::AreEqual(stats->get_total_devices(), 0);
			delete stats;
			stats = new Stats();
			stats->to_map(r_units[0], 3);
			Assert::AreNotEqual(stats->get_total_devices(), 0);
			stats->increase(r_units[0], 3);
			Assert::AreEqual(stats->get_count(r_units[0]), 6);
			stats->decrease(r_units[0], 5);
			Assert::AreEqual(stats->get_count(r_units[0]), 1);
			stats->remove(r_units[0]);
			Assert::AreEqual(stats->get_total_devices(), 0);
			Assert::AreEqual(stats->get_total(), 0);
		}
	};

	TEST_CLASS(Inheritance) {
	public:

		/*
		* ¬ тестируемых методах производитс€ проверка
		* работы класса Stats
		*/

		TEST_METHOD(IerarhyTest) {
			const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
			std::array<int, 32> clients = { 1, 2, 3 };
			std::array<int, 5> address = { 10, 11, 12, 13, 14 };
			std::string protocol = "sftp://";
			std::string ssid = "CoolWLAN";
			std::string passwd = "qwerty123";
			Router r(packets, clients, address, protocol, ssid, passwd);
			for (int i = 0; i < 5; i++)
				Assert::AreEqual(r.get_address()[i], address[i]);
			Assert::AreEqual(r.get_packets(), packets);
			if (r.get_clients() != clients) Assert::Fail(L"Clients are not the same");
			Assert::AreEqual(r.get_protocol(), protocol);
			Assert::AreEqual(r.get_ssid(), ssid);
		}
	};
}

namespace Container {

	TEST_CLASS(Storing) {

	public:

		/*
		* ¬ тестируемых методах провер€етс€ правильно ли
		* в	классе-контейнере сорханены объекты классов
		*/

		TEST_METHOD(SwitchObj) {
			const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
			std::array<int, 32> clients = { 1, 2, 3 };
			std::array<int, 5> address = { 10, 11, 12, 13, 14 };
			Switch* s_def = new Switch(packets, clients, address);
			Switch** s_units = new Switch * [5] {
				new Switch(clients),
				new Switch(address),
				new Switch(clients, address),
				new Switch(packets, clients, address),
				new Switch(*s_def)
			};

			ServerRoom<Switch> s_cont = ServerRoom<Switch>();
			for (int i = 0; i < 5; i++)
				s_cont = s_cont + *s_units[i];

			for (int i = 0; i < 5; i++)
				if (s_cont.get_array()[i] != s_units[i]) Assert::Fail(L"Wrong object getted from the contaner");
		}

		TEST_METHOD(RouterObj) {
			const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
			std::array<int, 32> clients = { 1, 2, 3 };
			std::array<int, 5> address = { 10, 11, 12, 13, 14 };
			std::string ssid = "CoolWLAN";
			std::string passwd = "qwerty123";
			std::string protocol = "sftp://";
			Router* r_def = new Router(packets, clients, address, protocol, ssid, passwd);
			Router** r_units = new Router * [3] {
				new Router(ssid, passwd),
				new Router(*r_def),
				new Router(packets, clients, address, protocol, ssid, passwd)
			};

			ServerRoom<Router> r_cont = ServerRoom<Router>();
			for (int i = 0; i < 3; i++)
				r_cont = r_cont + *r_units[i];

			for (int i = 0; i < 3; i++)
			{
				const Router* test = r_cont.get_array()[i];
				const Router* test1 = r_units[i];
				if (test != test1) Assert::Fail(L"Wrong object getted from the contaner");
			}
		}
	};

	TEST_CLASS(Search) {
	public:

		/*
		* ¬ тестируемых методах провер€етс€ правильно производитс€
		* поиск объектов по контейнеру
		*/

		TEST_METHOD(SwitchObj) {
			const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
			std::array<int, 32> clients = { 1, 2, 3 };
			std::array<int, 5> address = { 10, 11, 12, 13, 14 };
			Switch* s_def = new Switch(packets, clients, address);
			Switch** s_units = new Switch * [5] {
				new Switch(clients),
				new Switch(address),
				new Switch(clients, address),
				new Switch(packets, clients, address),
				new Switch(*s_def)
			};
			ServerRoom<Switch> s_cont = ServerRoom<Switch>();
			for (int i = 0; i < 5; i++)
				s_cont = s_cont + *s_units[i];
			const Switch* sw = s_cont.search(address);
			if (sw != s_units[1]) Assert::Fail(L"Objects are not the same");
		}

		TEST_METHOD(RouterObj) {
			const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
			std::array<int, 32> clients = { 1, 2, 3 };
			std::array<int, 5> address = { 10, 11, 12, 13, 14 };
			std::string ssid = "CoolWLAN";
			std::string passwd = "qwerty123";
			std::string protocol = "sftp://";
			Router* r_def = new Router(packets, clients, address, protocol, ssid, passwd);
			Router** r_units = new Router * [3] {
				new Router(ssid, passwd),
				new Router(*r_def),
				new Router(packets, clients, address, protocol, ssid, passwd)
			};
			ServerRoom<Router> r_cont = ServerRoom<Router>();
			for (int i = 0; i < 5; i++)
				r_cont = r_cont + *r_units[i];
			const Router* rt = r_cont.search(address);
			if (rt != r_units[1]) Assert::Fail(L"Objects are not the same");
		}
	};

	TEST_CLASS(Sort) {
	public:

		/*
		* ¬ тестируемых методах правильно ли производитс€
		* сортировка объектов в контейнере
		*/

		TEST_METHOD(SwitchObj) {
			std::array<int, 32> clients1 = { 1, 2, 3 };
			std::array<int, 32> clients2 = { 1, 2, 3, 4 };
			std::array<int, 32> clients3 = { 1, 2, 3, 4, 5 };
			Switch** ls_units = new Switch * [3] {
				new Switch(clients1),
				new Switch(clients2),
				new Switch(clients3)
			};
			ServerRoom<Switch> s_cont = ServerRoom<Switch>();
			for (int i = 0; i < 3; i++)
				s_cont = s_cont + *ls_units[i];
			s_cont.sort();
			Assert::AreEqual(s_cont.get_array()[0]->clients_count(), 3);
			Assert::AreEqual(s_cont.get_array()[2]->clients_count(), 5);
		}

		TEST_METHOD(RouterObj) {
			const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
			std::array<int, 32> clients1 = { 1, 2, 3 };
			std::array<int, 32> clients2 = { 1, 2, 3, 4 };
			std::array<int, 32> clients3 = { 1, 2, 3, 4, 5 };
			std::array<int, 5> address = { 10, 11, 12, 13, 14 };
			std::string ssid = "CoolWLAN";
			std::string passwd = "qwerty123";
			std::string protocol = "sftp://";
			Router** lr_units = new Router * [3] {
				new Router(packets, clients1, address, protocol, ssid, passwd),
				new Router(packets, clients2, address, protocol, ssid, passwd),
				new Router(packets, clients3, address, protocol, ssid, passwd)
			};
			ServerRoom<Router> r_cont = ServerRoom<Router>();
			for (int i = 0; i < 3; i++)
				r_cont = r_cont + *lr_units[i];
			r_cont.sort();
			Assert::AreEqual(r_cont.get_array()[0]->clients_count(), 3);
			Assert::AreEqual(r_cont.get_array()[2]->clients_count(), 5);
		}
	};

	TEST_CLASS(Operators) {
	public:

		/*
		* ¬ тестируемых методах производитс€ проверка
		* работы перегруженных операторов в объектах
		*/

		TEST_METHOD(SwitchObj) {
			const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
			std::array<int, 32> clients = { 1, 2, 3 };
			std::array<int, 5> address = { 10, 11, 12, 13, 14 };
			Switch* s_def = new Switch(packets, clients, address);
			Switch** s_units = new Switch * [5] {
				new Switch(clients),
				new Switch(address),
				new Switch(clients, address),
				new Switch(packets, clients, address),
				new Switch(*s_def)
			};
			Switch* sw = new Switch();
			ServerRoom<Switch> c_sw = ServerRoom<Switch>();
			c_sw = c_sw + *sw;
			if (c_sw.get_array()[0] != sw) Assert::Fail(L"Objects are not the same");
			c_sw--;
			Assert::AreEqual(c_sw.get_size(), 0);
			ServerRoom<Switch> s_cont = ServerRoom<Switch>();
			for (int i = 0; i < 3; i++)
				s_cont = s_cont + *s_units[i];
			if (s_cont[2] != s_units[2]) Assert::Fail(L"Objects are not the same");
			ServerRoom<Switch> s_cont_1 = ServerRoom<Switch>();
			for (int i = 0; i < 3; i++)
				s_cont_1 = s_cont_1 + *s_units[i];
			ServerRoom<Switch> s_cont_2 = ServerRoom<Switch>();
			for (int i = 0; i < 3; i++)
				s_cont_2 = s_cont_2 + *s_units[i];
			if (!(s_cont_1 == s_cont_2)) Assert::Fail(L"Objects are not the same");
		}

		TEST_METHOD(RouterObj) {
			const double* packets = new double[10] {15.6, 10.4, 54.32, 4.54, 31.542, 4.5, 45.7, 2.5, 24.5, 3.2};
			std::array<int, 32> clients = { 1, 2, 3 };
			std::array<int, 5> address = { 10, 11, 12, 13, 14 };
			std::string ssid = "CoolWLAN";
			std::string passwd = "qwerty123";
			std::string protocol = "sftp://";
			Router* r_def = new Router(packets, clients, address, protocol, ssid, passwd);
			Router** r_units = new Router * [3] {
				new Router(ssid, passwd),
				new Router(*r_def),
				new Router(packets, clients, address, protocol, ssid, passwd)
			};
			Router* rt = new Router();
			ServerRoom<Router> c_rt = ServerRoom<Router>();
			c_rt = c_rt + *rt;
			if (c_rt.get_array()[0] != rt) Assert::Fail(L"Operator + does not add object");
			c_rt--;
			Assert::AreEqual(c_rt.get_size(), 0);
			ServerRoom<Router> r_cont = ServerRoom<Router>();
			for (int i = 0; i < 3; i++)
				r_cont = r_cont + *r_units[i];
			if (r_cont[2] != r_units[2]) Assert::Fail(L"Operator + does not add object");
			ServerRoom<Router> r_cont_1 = ServerRoom<Router>();
			for (int i = 0; i < 3; i++)
				r_cont_1 = r_cont_1 + *r_units[i];
			ServerRoom<Router> r_cont_2 = ServerRoom<Router>();
			for (int i = 0; i < 3; i++)
				r_cont_2 = r_cont_2 + *r_units[i];
			if (!(r_cont_2 == r_cont_2)) Assert::Fail(L"Operator == does not work properly");
		}
	};

}
