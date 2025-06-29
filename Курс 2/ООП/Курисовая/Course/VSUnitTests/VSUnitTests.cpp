#include "pch.h"
#include "CppUnitTest.h"
#include "../NetDevices/src/devices/repeater.h"
#include "../NetDevices/src/devices/wl_repeater.h"
#include "../NetDevices/src/devices/switch.h"
#include "../NetDevices/src/devices/gateway.h"
#include "../NetDevices/src/devices/router.h"
#include "../NetDevices/src/containers/data_center.h"
#include "../NetDevices/src/containers/server_room.h"
#include "../NetDevices/src/misc/address.h"
#include "../NetDevices/src/misc/client.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NetDevices
{
	TEST_CLASS(MAllocTest)
	{
		/**
		* В тестируемых методах проверяется работают ли
		* конструкторы и деструкторы (выделение и очистка памяти)
		*/

	public:
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
	};

	TEST_CLASS(GetTest)
	{
		/**
		* В тестируемых методах проверяется правильно ли
		* в объектах классов сохраняются данные
		*/

	private:
		MAC_Address address = MAC_Address(std::array<unsigned char, 6> { 10, 11, 12, 13, 14 });
		std::vector<unsigned char> bytes = { 15, 10, 54, 45, 31, 4, 45, 2, 24, 32 };
		std::vector<Client> clients = { Client(), Client(), Client() };
		std::string ssid = "CoolWLAN";
		std::string passwd = "qwerty123";
		std::string protocol = "sftp://";

	public:
		TEST_METHOD(CLS_Repeater)
		{
			Repeater rep(bytes, address);
			Assert::AreEqual(rep.get_address().as_string(), address.as_string());
			if (rep.get_bytes() != bytes) Assert::Fail(L"Bytes are not the same");
			if (rep.get_clients() != std::vector<Client>{}) Assert::Fail(L"Clients are not empty");
		}

		TEST_METHOD(CLS_WLRepeater)
		{
			WLRepeater wl_rep(bytes, address, ssid, passwd);
			Assert::AreEqual(wl_rep.get_address().as_string(), address.as_string());
			if (wl_rep.get_bytes() != bytes) Assert::Fail(L"Bytes are not the same");
			if (wl_rep.get_clients() != std::vector<Client>{}) Assert::Fail(L"Clients are not empty");
			Assert::AreEqual(wl_rep.get_ssid(), ssid);
		}

		TEST_METHOD(CLS_Switch)
		{
			Switch sw(bytes, clients, address);
			Assert::AreEqual(sw.get_address().as_string(), address.as_string());
			if (sw.get_bytes() != bytes) Assert::Fail(L"Bytes are not the same");
			Assert::AreEqual(sw.get_capacity(), 32);
			if (sw.get_clients() != clients) Assert::Fail(L"Clients are not the same");
		}

		TEST_METHOD(CLS_Gateway)
		{
			Gateway gw(bytes, clients, address, protocol);
			Assert::AreEqual(gw.get_address().as_string(), address.as_string());
			if (gw.get_bytes() != bytes) Assert::Fail(L"Bytes are not the same");
			Assert::AreEqual(gw.get_capacity(), 32);
			if (gw.get_clients() != clients) Assert::Fail(L"Clients are not the same");
			Assert::AreEqual(gw.get_protocol(), protocol);
		}

		TEST_METHOD(CLS_Router)
		{
			Router r(bytes, clients, address, protocol, ssid, passwd);
			Assert::AreEqual(r.get_address().as_string(), address.as_string());
			if (r.get_bytes() != bytes) Assert::Fail(L"Bytes are not the same");
			Assert::AreEqual(r.get_capacity(), 32);
			if (r.get_clients() != clients) Assert::Fail(L"Clients are not the same");
			Assert::AreEqual(r.get_protocol(), protocol);
			Assert::AreEqual(r.get_ssid(), ssid);
		}
	};

	TEST_CLASS(SetTest)
	{

		/**
		* В тестируемых методах проверяется правильно ли
		* в объекты передаются данные
		*/

	private:
		MAC_Address address = MAC_Address(std::array<unsigned char, 6> { 10, 11, 12, 13, 14 });
		std::vector<unsigned char> bytes = { 15, 10, 54, 45, 31, 4, 45, 2, 24, 32 };
		std::vector<Client> clients = { Client(), Client(), Client() };
		std::string ssid = "CoolWLAN";
		std::string passwd = "qwerty123";
		std::string protocol = "sftp://";

	public:
		TEST_METHOD(CLS_Repeater)
		{
			Repeater rep = Repeater();
			rep.receive(bytes);
			rep.set_address(address);
			Assert::AreEqual(rep.get_address().as_string(), address.as_string());
			if (rep.get_bytes() != bytes) Assert::Fail(L"Bytes are not the same");
			if (rep.get_clients() != std::vector<Client>{}) Assert::Fail(L"Clients are not empty");
		}

		TEST_METHOD(CLS_WLRepeater)
		{
			WLRepeater wl_rep = WLRepeater();
			wl_rep.receive(bytes);
			wl_rep.set_address(address);
			wl_rep.set_ssid(ssid);
			wl_rep.set_passwd(passwd);
			Assert::AreEqual(wl_rep.get_address().as_string(), address.as_string());
			if (wl_rep.get_bytes() != bytes) Assert::Fail(L"Bytes are not the same");
			if (wl_rep.get_clients() != std::vector<Client>{}) Assert::Fail(L"Clients are not empty");
			Assert::AreEqual(wl_rep.get_ssid(), ssid);
		}

		TEST_METHOD(CLS_Switch)
		{
			Switch sw = Switch();
			sw.set_address(address);
			sw.receive(bytes);
			sw.set_capacity(16);
			sw.set_clients(clients);
			Assert::AreEqual(sw.get_address().as_string(), address.as_string());
			if (sw.get_bytes() != bytes) Assert::Fail(L"Bytes are not the same");
			Assert::AreEqual(sw.get_capacity(), 16);
			if (sw.get_clients() != clients) Assert::Fail(L"Clients are not the same");
		}

		TEST_METHOD(CLS_Gateway)
		{
			Gateway gw = Gateway();
			gw.receive(bytes);
			gw.set_address(address);
			gw.set_capacity(18);
			gw.set_clients(clients);
			gw.set_protocol(protocol);
			Assert::AreEqual(gw.get_address().as_string(), address.as_string());
			if (gw.get_bytes() != bytes) Assert::Fail(L"Bytes are not the same");
			Assert::AreEqual(gw.get_capacity(), 18);
			if (gw.get_clients() != clients) Assert::Fail(L"Clients are not the same");
			Assert::AreEqual(gw.get_protocol(), protocol);
		}

		TEST_METHOD(CLS_Router)
		{
			Router r = Router();
			r.receive(bytes);
			r.set_address(address);
			r.set_capacity(20);
			r.set_clients(clients);
			r.set_protocol(protocol);
			r.set_ssid(ssid);
			r.set_passwd(passwd);
			Assert::AreEqual(r.get_address().as_string(), address.as_string());
			if (r.get_bytes() != bytes) Assert::Fail(L"Bytes are not the same");
			Assert::AreEqual(r.get_capacity(), 20);
			if (r.get_clients() != clients) Assert::Fail(L"Clients are not the same");
			Assert::AreEqual(r.get_protocol(), protocol);
			Assert::AreEqual(r.get_ssid(), ssid);
		}
	};

	TEST_CLASS(ConnectTest) {

		/**
		* В тестируемых методах проверяется правильно ли
		* работает логика подключения клиентов к устройствам
		*/

	private:
		std::vector<Client> clients = { Client(), Client(), Client() };
		std::vector<Client> wl_clients = { 
			Client("1", MAC_Address(), {}, ClientType::Wireless), 
			Client("2", MAC_Address(), {}, ClientType::Wireless),
			Client("3", MAC_Address(), {}, ClientType::Wireless)
		};
		std::string ssid = "CoolWLAN";
		std::string passwd = "qwerty123";
		std::string bad_passwd = "qwerty1234";

	public:
		TEST_METHOD(RepeaterObj) {
			Repeater r = Repeater();

			// Подключение
			r.connect(clients[0]);
			Assert::AreEqual(r.clients_count(), 1);
			try {
				r.connect(clients[1]);
				Assert::Fail(L"Device pass multiple clients");
			}
			catch (std::overflow_error) {}

			// Отключение
			Assert::AreEqual(r.clients_count(), 1);
			r.disconnect(clients[0]);
			Assert::AreEqual(r.clients_count(), 0);
		}

		TEST_METHOD(WLRepeaterObj) {
			WLRepeater r = WLRepeater(ssid, passwd);

			// Подключение
			r.connect(wl_clients[0], ssid, passwd);
			Assert::AreEqual(r.clients_count(), 1);
			try {
				r.connect(wl_clients[1], ssid, passwd);
				Assert::Fail(L"Device pass multiple clients");
			}
			catch (std::overflow_error) {}

			// Отключение
			Assert::AreEqual(r.clients_count(), 1);
			r.disconnect(wl_clients[0]);
			Assert::AreEqual(r.clients_count(), 0);

			// Подключение с неверным паролем
			try {
				r.connect(wl_clients[1], ssid, bad_passwd);
				Assert::Fail(L"Device passes bad passwd");
			}
			catch (std::invalid_argument) {}

			// Подключение по WPS
			r.wps_init();
			r.connect(wl_clients[1]);
			Assert::AreEqual(r.is_wps(), false);
		}

		TEST_METHOD(SwitchObj) {
			Switch sw = Switch();

			// Подключение
			for (int i = 0; i < clients.size(); i++)
				sw.connect(clients[i]);
			Assert::AreEqual(sw.clients_count(), (int)clients.size());

			// Отключение
			for (int i = 0; i < clients.size(); i++)
				sw.disconnect(clients[i]);
			Assert::AreEqual(sw.clients_count(), 0);
		}

		TEST_METHOD(GatewayObj) {
			Gateway g = Gateway();

			// Подключение
			for (int i = 0; i < clients.size(); i++)
				g.connect(clients[i]);
			Assert::AreEqual(g.clients_count(), (int)clients.size());

			// Отключение
			for (int i = 0; i < clients.size(); i++)
				g.disconnect(clients[i]);
			Assert::AreEqual(g.clients_count(), 0);
		}

		TEST_METHOD(RouterObj) {
			Router r = Router(ssid, passwd);

			// Подключение
			for (int i = 0; i < clients.size(); i++)
				r.connect(clients[i]);
			Assert::AreEqual(r.clients_count(), (int)clients.size());

			// Отключение
			for (int i = 0; i < clients.size(); i++)
				r.disconnect(clients[i]);
			Assert::AreEqual(r.clients_count(), 0);

			// Подключение
			for (int i = 0; i < clients.size(); i++)
				r.connect(wl_clients[i], ssid, passwd);
			Assert::AreEqual(r.clients_count(), (int)clients.size());

			// Отключение
			for (int i = 0; i < clients.size(); i++)
				r.disconnect(wl_clients[i]);
			Assert::AreEqual(r.clients_count(), 0);

			// Подключение с неверным паролем
			try {
				r.connect(wl_clients[1], ssid, bad_passwd);
				Assert::Fail(L"Device passes bad passwd");
			}
			catch (std::invalid_argument) {}

			// Подключение по WPS
			r.wps_init();
			r.connect(wl_clients[1]);
			Assert::AreEqual(r.is_wps(), false);
		}
	};

	TEST_CLASS(Polymorph) {
	public:

		TEST_METHOD(OBJ_Repeater) {
			Gateway* obj = static_cast<Gateway*>(new Repeater());
			Assert::AreEqual(obj->type_name(), std::string("Repeater"));
		}

		TEST_METHOD(OBJ_WLRepeater) {
			Repeater* obj = dynamic_cast<Repeater*>(new WLRepeater());
			Assert::AreEqual(obj->type_name(), std::string("WLRepeater"));
		}

		TEST_METHOD(OBJ_Switch) {
			Router* obj = static_cast<Router*>(new Switch());
			Assert::AreEqual(obj->type_name(), std::string("Switch"));
		}

		TEST_METHOD(OBJ_Gateway) {
			Router* obj = static_cast<Router*>(new Gateway());
			Assert::AreEqual(obj->type_name(), std::string("Gateway"));
		}

		TEST_METHOD(OBJ_Router) {
			Gateway* obj = dynamic_cast<Gateway*>(new Router());
			Assert::AreEqual(obj->type_name(), std::string("Router"));
		}
	};
}

namespace Containers {

	namespace ServerRoomContainer {
		TEST_CLASS(Storing) {

			/*
			* В тестируемых методах проверяется правильно ли
			* в	классе-контейнере сорханены объекты классов
			*/

		private:
			MAC_Address address = MAC_Address(std::array<unsigned char, 6> { 10, 11, 12, 13, 14 });
			std::vector<unsigned char> bytes = { 15, 10, 54, 45, 31, 4, 45, 2, 24, 32 };
			std::vector<Client> clients = { Client(), Client(), Client() };
			std::string ssid = "CoolWLAN";
			std::string passwd = "qwerty123";
			std::string protocol = "sftp://";

		public:
			TEST_METHOD(SwitchObj) {
				Switch s_def = Switch(bytes, clients, address);
				std::vector <Switch*> s_units = {
					new Switch(clients),
					new Switch(address),
					new Switch(clients, address),
					new Switch(bytes, clients, address),
					new Switch(s_def)
				};

				ServerRoom<Switch> s_cont = ServerRoom<Switch>();
				for (int i = 0; i < s_units.size(); i++)
					s_cont.add(*s_units[i]);

				for (int i = 0; i < s_units.size(); i++)
					if (s_cont.get_vector()[i] != s_units[i])
						Assert::Fail(L"Wrong object getted from the contaner");
			}

			TEST_METHOD(RouterObj) {
				Router r_def = Router(bytes, clients, address, protocol, ssid, passwd);
				std::vector<Router*> r_units = {
					new Router(ssid, passwd),
					new Router(r_def),
					new Router(bytes, clients, address, protocol, ssid, passwd)
				};

				ServerRoom<Router> r_cont = ServerRoom<Router>();
				for (int i = 0; i < r_units.size(); i++)
					r_cont.add(*r_units[i]);

				for (int i = 0; i < 3; i++)
				{
					if (r_cont.get_vector()[i] != r_units[i])
						Assert::Fail(L"Wrong object getted from the contaner");
				}
			}
		};

		TEST_CLASS(Search) {

			/*
			* В тестируемых методах проверяется правильно производится
			* поиск объектов по контейнеру
			*/

		private:
			MAC_Address address = MAC_Address(std::array<unsigned char, 6> { 10, 11, 12, 13, 14 });
			std::vector<unsigned char> bytes = { 15, 10, 54, 45, 31, 4, 45, 2, 24, 32 };
			std::vector<Client> clients = { Client(), Client(), Client() };
			std::string ssid = "CoolWLAN";
			std::string passwd = "qwerty123";
			std::string protocol = "sftp://";

		public:

			TEST_METHOD(SwitchObj) {
				Switch s_def = Switch(bytes, clients, address);
				std::vector<Switch*> s_units = {
					new Switch(clients),
					new Switch(address),
					new Switch(clients, address),
					new Switch(bytes, clients, address),
					new Switch(s_def)
				};
				ServerRoom<Switch> s_cont = ServerRoom<Switch>();
				for (int i = 0; i < s_units.size(); i++)
					s_cont.add(*s_units[i]);
				std::vector<Switch*> v_sw = s_cont.search(address);
				if (v_sw[0] != s_units[1]) Assert::Fail(L"Objects are not the same");
			}

			TEST_METHOD(RouterObj) {
				Router r_def = Router(bytes, clients, address, protocol, ssid, passwd);
				std::vector<Router*> r_units = {
					new Router(ssid, passwd),
					new Router(r_def),
					new Router(bytes, clients, address, protocol, ssid, passwd)
				};
				ServerRoom<Router> r_cont = ServerRoom<Router>();
				for (int i = 0; i < r_units.size(); i++)
					r_cont.add(*r_units[i]);
				std::vector<Router*> v_rt = r_cont.search(address);
				if (v_rt[0] != r_units[1]) Assert::Fail(L"Objects are not the same");
			}
		};

		TEST_CLASS(Sort) {

			/*
			* В тестируемых методах проверяется правильно ли производится
			* сортировка объектов в контейнере
			*/

		private:
			MAC_Address address1 = MAC_Address(std::array<unsigned char, 6>{3, 2, 1, 6, 5, 4});
			MAC_Address address2 = MAC_Address(std::array<unsigned char, 6>{1, 2, 3, 4, 5, 6});
			MAC_Address address3 = MAC_Address(std::array<unsigned char, 6>{6, 5, 4, 3, 2, 1});

		public:

			TEST_METHOD(RepeaterObj) {
				std::vector<Repeater*> r_units = {
					new Repeater(address1),
					new Repeater(address2),
					new Repeater(address3)
				};
				ServerRoom<Repeater> r_cont = ServerRoom<Repeater>();
				for (int i = 0; i < r_units.size(); i++)
					r_cont.add(*r_units[i]);
				r_cont.sort();
				if (r_cont.get_vector()[0]->get_address() != address2) Assert::Fail(L"Address is not the same");
				if (r_cont.get_vector()[2]->get_address() != address3) Assert::Fail(L"Address is not the same");
			}
			TEST_METHOD(SwitchObj) {
				std::vector<Switch*> s_units = {
					new Switch(std::vector<Client>{Client(), Client()}),
					new Switch(std::vector<Client>{Client()}),
					new Switch(std::vector<Client>{Client(), Client(), Client()})
				};
				ServerRoom<Switch> s_cont = ServerRoom<Switch>();
				for (int i = 0; i < s_units.size(); i++)
					s_cont.add(*s_units[i]);
				s_cont.sort();
				if (s_cont.get_vector()[0]->clients_count() != 1) Assert::Fail(L"Client count is not the same");
				if (s_cont.get_vector()[2]->clients_count() != 3) Assert::Fail(L"Client count is not the same");
			}
		};

		TEST_CLASS(Operators) {

		private:
			MAC_Address address = MAC_Address(std::array<unsigned char, 6> { 10, 11, 12, 13, 14 });
			std::vector<unsigned char> bytes = { 15, 10, 54, 45, 31, 4, 45, 2, 24, 32 };
			std::vector<Client> clients = { Client(), Client(), Client() };
			std::string ssid = "CoolWLAN";
			std::string passwd = "qwerty123";
			std::string protocol = "sftp://";

			/*
			* В тестируемых методах производится проверка
			* работы перегруженных операторов в объектах
			*/

		public:

			TEST_METHOD(SwitchObj) {
				Switch s_def = Switch(bytes, clients, address);
				std::vector<Switch*> s_units = {
					new Switch(clients),
					new Switch(address),
					new Switch(clients, address),
					new Switch(bytes, clients, address),
					new Switch(s_def)
				};
				Switch sw = Switch();
				ServerRoom<Switch> c_sw = ServerRoom<Switch>();

				c_sw.add(sw);
				c_sw--;
				Assert::AreEqual(c_sw.size(), 0);

				ServerRoom<Switch> s_cont_1 = ServerRoom<Switch>();
				for (int i = 0; i < s_units.size(); i++)
					s_cont_1.add(*s_units[i]);
				ServerRoom<Switch> s_cont_2 = ServerRoom<Switch>();
				for (int i = 0; i < s_units.size(); i++)
					s_cont_2.add(*s_units[i]);
				if (!(s_cont_1 == s_cont_2)) Assert::Fail(L"Operator == does not work properly");
				if (s_cont_1 != s_cont_2) Assert::Fail(L"Operator != does not work properly");
			}

			TEST_METHOD(RouterObj) {
				Router r_def = Router(bytes, clients, address, protocol, ssid, passwd);
				std::vector<Router*> r_units = {
					new Router(ssid, passwd),
					new Router(r_def),
					new Router(bytes, clients, address, protocol, ssid, passwd)
				};
				Router rt = Router();
				ServerRoom<Router> c_rt = ServerRoom<Router>();

				c_rt.add(rt);
				c_rt--;
				Assert::AreEqual(c_rt.size(), 0);

				ServerRoom<Router> r_cont_1 = ServerRoom<Router>();
				for (int i = 0; i < r_units.size(); i++)
					r_cont_1.add(*r_units[i]);
				ServerRoom<Router> r_cont_2 = ServerRoom<Router>();
				for (int i = 0; i < r_units.size(); i++)
					r_cont_2.add(*r_units[i]);
				if (!(r_cont_2 == r_cont_2)) Assert::Fail(L"Operator == does not work properly");
				if (r_cont_2 != r_cont_2) Assert::Fail(L"Operator != does not work properly");
			}
		};
	}

	namespace DataCenterContainer {

		MAC_Address address = MAC_Address(std::array<unsigned char, 6> { 10, 11, 12, 13, 14 });
		std::vector<unsigned char> bytes = { 15, 10, 54, 45, 31, 4, 45, 2, 24, 32 };
		std::vector<Client> clients = { Client(), Client(), Client() };
		std::string ssid = "CoolWLAN";
		std::string passwd = "qwerty123";
		std::string protocol = "sftp://";
		Switch s_def = Switch(bytes, clients, address);
		std::vector <Switch*> s_units = {
			new Switch(clients),
			new Switch(address),
			new Switch(clients, address),
			new Switch(bytes, clients, address),
			new Switch(s_def)
		};
		Router r_def = Router(bytes, clients, address, protocol, ssid, passwd);
		std::vector<Router*> r_units = {
			new Router(ssid, passwd),
			new Router(r_def),
			new Router(bytes, clients, address, protocol, ssid, passwd)
		};

		TEST_CLASS(Adding) {

			/*
			* В тестируемых методах проверяется правильно ли
			* в	класс-контейнер добавляются объекты
			*/

		public:
			TEST_METHOD(SwitchObj) {
				ServerRoom<Switch> s_cont = ServerRoom<Switch>();
				for (int i = 0; i < s_units.size(); i++)
					s_cont.add(*s_units[i]);

				DataCenter srv_cont = DataCenter();
				srv_cont.add(&s_cont);
				Assert::AreEqual(srv_cont.size(), 1);
			}

			TEST_METHOD(RouterObj) {
				ServerRoom<Router> r_cont = ServerRoom<Router>();
				for (int i = 0; i < r_units.size(); i++)
					r_cont.add(*r_units[i]);

				DataCenter srv_cont = DataCenter();
				srv_cont.add(&r_cont);
				Assert::AreEqual(srv_cont.size(), 1);
			}
		};

		TEST_CLASS(Getting) {

			/*
			* В тестируемых методах проверяется правильно ли
			* в	классе-контейнере сохранены объекты
			*/

		public:
			TEST_METHOD(SwitchObj) {
				ServerRoom<Switch> s_cont = ServerRoom<Switch>();
				for (int i = 0; i < s_units.size(); i++)
					s_cont.add(*s_units[i]);

				DataCenter srv_cont = DataCenter();
				srv_cont.add(&s_cont);

				std::vector<void*> v_ptr = srv_cont.get_vector();
				if (*static_cast<ServerRoom<Switch>*>(v_ptr[0]) != s_cont)
					Assert::Fail(L"Objects are not the same");

				Assert::AreEqual(srv_cont.get_total_devices(), 5);
			}

			TEST_METHOD(RouterObj) {
				ServerRoom<Router> r_cont = ServerRoom<Router>();
				for (int i = 0; i < r_units.size(); i++)
					r_cont.add(*r_units[i]);

				DataCenter srv_cont = DataCenter();
				srv_cont.add(&r_cont);

				std::vector<void*> v_ptr = srv_cont.get_vector();
				if (*static_cast<ServerRoom<Router>*>(v_ptr[0]) != r_cont)
					Assert::Fail(L"Objects are not the same");

				Assert::AreEqual(srv_cont.get_total_devices(), 3);
			}
		};

		TEST_CLASS(Clearing) {

			/*
			* В тестируемых методах проверяется правильно ли
			* в	классе-контейнере сохранены объекты
			*/

		public:
			TEST_METHOD(SwitchObj) {
				ServerRoom<Switch> s_cont = ServerRoom<Switch>();
				for (int i = 0; i < s_units.size(); i++)
					s_cont.add(*s_units[i]);

				DataCenter srv_cont = DataCenter();
				srv_cont.add(&s_cont);
				Assert::AreEqual(srv_cont.size(), 1);

				srv_cont.clear();
				Assert::AreEqual(srv_cont.size(), 0);
			}

			TEST_METHOD(RouterObj) {
				ServerRoom<Router> r_cont = ServerRoom<Router>();
				for (int i = 0; i < r_units.size(); i++)
					r_cont.add(*r_units[i]);

				DataCenter srv_cont = DataCenter();
				srv_cont.add(&r_cont);
				Assert::AreEqual(srv_cont.size(), 1);

				srv_cont.clear();
				Assert::AreEqual(srv_cont.size(), 0);
			}
		};
	}
}

namespace Misc {

	TEST_CLASS(Address) {

		/*
		* В тестируемых методах правильно ли работает
		* тип данных MAC_Address
		*/

	public:

		TEST_METHOD(Create) {
			MAC_Address mac1 = MAC_Address();
			MAC_Address mac2 = MAC_Address("75:C8:58:A2:55:CF");
			try {
				MAC_Address mac3 = MAC_Address("75:C8:58:");
				Assert::Fail(L"Address passes the non valid string");
			}
			catch (std::length_error) {}
			try {
				MAC_Address mac4 = MAC_Address("75:C8:58:A2:55:999");
				Assert::Fail(L"Address passes the non valid string");
			}
			catch (std::overflow_error) {}
			try {
				MAC_Address mac5 = MAC_Address("75:C8:58:ZZ:55:CF");
				Assert::Fail(L"Address passes the non valid string");
			}
			catch (std::invalid_argument) {}
		}

		TEST_METHOD(String) {
			MAC_Address mac1 = MAC_Address("75:C8:58:A2:55:CF");
			Assert::AreEqual(mac1.as_string(), std::string("75:C8:58:A2:55:CF"));
			MAC_Address mac2 = MAC_Address("AA:BB:CC:DD:EE:FF");
			Assert::AreEqual(mac2.as_string(), std::string("AA:BB:CC:DD:EE:FF"));
			MAC_Address mac3 = MAC_Address("00:00:00:00:00:00");
			Assert::AreEqual(mac3.as_string(), std::string("00:00:00:00:00:00"));
		}

		TEST_METHOD(Generate) {
			MAC_Address mac = MAC_Address();
			std::string first = mac.as_string();
			mac.generate();
			std::string second = mac.as_string();
			Assert::AreNotEqual(first, second);
		}
	};

	TEST_CLASS(Clients) {

		/*
		* В тестируемых методах правильно ли работает
		* тип данных Client
		*/

	private:
		std::string name = "SomeName";
		MAC_Address address = MAC_Address("75:C8:58:A2:55:CF");

	public:
		TEST_METHOD(GetSetTest) {
			Client cli = Client();
			cli.set_name(name);
			cli.set_address(address);
			cli.set_type(ClientType::Wireless);
			Assert::AreEqual(cli.get_name(), name);
			if (cli.get_address() != address) Assert::Fail();
			if (cli.get_type() != ClientType::Wireless) Assert::Fail();
		}

		TEST_METHOD(Operators) {
			Client cli1 = Client(address);
			Client cli2 = Client(address);
			Client cli3 = Client();
			if (!(cli1 == cli2)) Assert::Fail(L"Operator == does not work properly");
			if (cli1 == cli3) Assert::Fail(L"Operator == does not work properly");
			if (!(cli1 != cli3)) Assert::Fail(L"Operator != does not work properly");
			if (cli1 != cli2) Assert::Fail(L"Operator != does not work properly");
		}
	};

}
