#include <iostream>
#include <string>
#include <vector>
// =============全局函数做友元====================
namespace space1
{
    class Building
    {
        public:
        Building(std::string sittingRoom, std::string bedRoom) : m_SittingRoom(sittingRoom), m_BedRoom(bedRoom) {} 
        std::string m_SittingRoom;
        friend void laoWang(Building &building);

        private:
        std::string m_BedRoom;
    };

    void laoWang(Building &building)
    {
        std::cout << "global function ========" << building.m_SittingRoom << std::endl;
        std::cout << "global function ========" << building.m_BedRoom << std::endl;
    }
}

//友元类
namespace space2
{
    class Building
    {
        friend class LaoWang;
        public:
        Building(std::string sittingRoom, std::string bedRoom) : m_SittingRoom(sittingRoom), m_BedRoom(bedRoom) {} 
        std::string m_SittingRoom;

        private:
        std::string m_BedRoom;
    };

    class LaoWang
    {
        public:
        LaoWang()
        {
            std::cout << "global function ========" << m_building.m_SittingRoom << std::endl;
            std::cout << "global function ========" << m_building.m_BedRoom << std::endl;
        }

        private:
        Building m_building{"sr", "br"};
    };
}


//成员函数做友元
namespace space3
{
    class Building;
    class LaoWang
    {
        public:
        LaoWang();
 
        void visit();


        private:
        //如果此时Building只有声明，这时候不能是值类型，只能是指针
        Building *m_building;
    };
    class Building
    {
        public:
        Building(std::string sittingRoom, std::string bedRoom) : m_SittingRoom(sittingRoom), m_BedRoom(bedRoom) {} 
        std::string m_SittingRoom;

        private:
        friend void LaoWang::visit();
        std::string m_BedRoom;
    };

    LaoWang::LaoWang()
    {
        m_building = new Building("sr", "br");
        std::cout << "global function ========" << m_building->m_SittingRoom << std::endl;
            // std::cout << "global function ========" << m_building.m_BedRoom << std::endl;
    }

    void
    LaoWang::visit()
    {
        std::cout << "friend function ========" << m_building->m_SittingRoom << std::endl;
        std::cout << "friend function ========" << m_building->m_BedRoom << std::endl;
    }
    
}


int main()
{
    space1::Building building("sr", "br");
    space1::laoWang(building);
}