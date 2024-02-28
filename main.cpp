class Bank_t{
    int id;
    std::string name;
 
    std::string money(){
        return "100$";//yes
    }
public:
    Bank_t(int i, std::string str) : id(i), name(str){}
    void set_id(int i){id = i;}
};

auto steal_impl(Bank_t& t);
template struct ThiefMember<Bank_t, &Bank_t::id, &Bank_t::name, &Bank_t::money>;

int main(void) {
    Bank_t bank(1, "ok");
    auto tp = steal_impl(bank);

    auto& id = bank.*(std::get<0>(tp)); // 1
    auto name = bank.*(std::get<1>(tp)); //ok

    auto money = (bank.*(std::get<2>(tp)))(); // 100$
    std::cout << "id: " << id << std::endl;
    std::cout << "name: " << name << std::endl;//20000
    std::cout << "money: " << money << std::endl;
    bank.set_id(2);
    std::cout << "id: " << id << std::endl;
    Stub stub;
