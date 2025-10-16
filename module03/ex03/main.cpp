#include "DiamondTrap.hpp"

// ANSI color codes
#define COLOR_RESET   "\033[0m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_RED     "\033[31m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_BOLD    "\033[1m"
#define COLOR_DIM     "\033[2m"

#define TEST_CASE(name) \
    std::cout << COLOR_CYAN << COLOR_BOLD << "\n=== " << name << " ===" << COLOR_RESET << std::endl;

#define TEST_RESULT(cond, msg) \
    if (cond) std::cout << COLOR_GREEN << "[PASS] " << COLOR_RESET << msg << std::endl; \
    else std::cout << COLOR_RED << "[FAIL] " << COLOR_RESET << msg << std::endl;

#define SEPARATOR() \
    std::cout << COLOR_DIM << "─────────────────────────────────────────" << COLOR_RESET << std::endl;

#define SECTION(name) \
    std::cout << COLOR_BLUE << "▶ " << name << COLOR_RESET << std::endl;

void testEx00() {
    TEST_CASE("Exercise 00: ClapTrap Basic Test")
    
    SECTION("Construction Phase")
    ClapTrap ct1("Basic");
    SEPARATOR()
    
    SECTION("Testing Phase")
    ct1.attack("Target1");
    ct1.takeDamage(5);
    ct1.beRepaired(3);
    TEST_RESULT(ct1.getHitPoints() == 8, "ClapTrap repaired and damaged correctly");
    ct1.takeDamage(20);
    TEST_RESULT(ct1.getHitPoints() <= 0, "ClapTrap dies on overkill");
    ct1.attack("Target2");
    SEPARATOR()
    
    SECTION("Destruction Phase")
}

void testEx01() {
    TEST_CASE("Exercise 01: ScavTrap Test")
    
    SECTION("Construction Phase")
    ScavTrap st1("Scavvy");
    SEPARATOR()
    
    SECTION("Testing Phase")
    st1.attack("Bandit");
    st1.takeDamage(30);
    st1.beRepaired(20);
    st1.guardGate();
    TEST_RESULT(st1.getHitPoints() == 90, "ScavTrap repaired and damaged correctly");
    st1.takeDamage(100);
    TEST_RESULT(st1.getHitPoints() <= 0, "ScavTrap dies on overkill");
    st1.attack("Bandit2");
    SEPARATOR()
    
    SECTION("Destruction Phase")
}

void testEx02() {
    TEST_CASE("Exercise 02: FragTrap Test")
    
    SECTION("Construction Phase")
    FragTrap ft1("Fraggy");
    SEPARATOR()
    
    SECTION("Testing Phase")
    ft1.attack("Raider");
    ft1.takeDamage(50);
    ft1.beRepaired(40);
    ft1.highFivesGuys();
    TEST_RESULT(ft1.getHitPoints() == 90, "FragTrap repaired and damaged correctly");
    ft1.takeDamage(200);
    TEST_RESULT(ft1.getHitPoints() <= 0, "FragTrap dies on overkill");
    ft1.attack("Raider2");
    SEPARATOR()
    
    SECTION("Destruction Phase")
}

void testEx03() {
    TEST_CASE("Exercise 03: DiamondTrap Test")
    
    SECTION("Construction Phase")
    DiamondTrap dt1("Diamond");
    SEPARATOR()
    
    SECTION("Testing Phase")
    dt1.attack("Boss");
    dt1.takeDamage(20);
    dt1.beRepaired(10);
    dt1.guardGate();
    dt1.highFivesGuys();
    dt1.whoAmI();
    TEST_RESULT(dt1.getHitPoints() == 90, "DiamondTrap repaired and damaged correctly");
    TEST_RESULT(dt1.getDiamondName() == "Diamond", "DiamondTrap name is correct");
    TEST_RESULT(dt1.getClapTrapName() == "Diamond_clap_name", "ClapTrap name in DiamondTrap is correct");
    dt1.takeDamage(200);
    TEST_RESULT(dt1.getHitPoints() <= 0, "DiamondTrap dies on overkill");
    dt1.attack("Boss2");
    dt1.whoAmI();
    SEPARATOR()
    
    TEST_CASE("DiamondTrap Copy/Assignment Test")
    SECTION("Copy Constructor Test")
    DiamondTrap dt2(dt1);
    dt2.whoAmI();
    TEST_RESULT(dt2.getDiamondName() == dt1.getDiamondName(), "Copy constructor preserves name");
    SEPARATOR()
    
    SECTION("Assignment Operator Test")
    DiamondTrap dt3("AnotherDiamond");
    SEPARATOR()
    dt3 = dt1;
    dt3.whoAmI();
    TEST_RESULT(dt3.getDiamondName() == dt1.getDiamondName(), "Assignment operator preserves name");
    SEPARATOR()
    
    TEST_CASE("Destructor Chain Test")
    SECTION("Temporary Object Creation")
    {
        DiamondTrap temp("TempDiamond");
        SEPARATOR()
        temp.whoAmI();
        SEPARATOR()
        SECTION("Temporary Object Destruction")
    }
    SEPARATOR()
    
    SECTION("Final Destruction Phase")
}

void showMenu() {
    std::cout << COLOR_YELLOW << COLOR_BOLD << "\n╔══════════════════════════════════════╗\n";
    std::cout << "║   C++ Module 03 - Test Suite        ║\n";
    std::cout << "╚══════════════════════════════════════╝" << COLOR_RESET << std::endl;
    std::cout << COLOR_CYAN << "[0] " << COLOR_RESET << "Exercise 00 - ClapTrap\n";
    std::cout << COLOR_CYAN << "[1] " << COLOR_RESET << "Exercise 01 - ScavTrap\n";
    std::cout << COLOR_CYAN << "[2] " << COLOR_RESET << "Exercise 02 - FragTrap\n";
    std::cout << COLOR_CYAN << "[3] " << COLOR_RESET << "Exercise 03 - DiamondTrap\n";
    std::cout << COLOR_CYAN << "[4] " << COLOR_RESET << "Run ALL Tests\n";
    std::cout << COLOR_RED << "[q] " << COLOR_RESET << "Quit\n";
    std::cout << COLOR_YELLOW << "\nSelect exercise: " << COLOR_RESET;
}

int main() {
    std::string choice;
    
    while (true) {
        showMenu();
        std::getline(std::cin, choice);
        
        if (choice == "0") {
            testEx00();
        }
        else if (choice == "1") {
            testEx01();
        }
        else if (choice == "2") {
            testEx02();
        }
        else if (choice == "3") {
            testEx03();
        }
        else if (choice == "4") {
            testEx00();
            testEx01();
            testEx02();
            testEx03();
        }
        else if (choice == "q" || choice == "Q") {
            std::cout << COLOR_MAGENTA << "\n👋 Goodbye!\n" << COLOR_RESET;
            break;
        }
        else {
            std::cout << COLOR_RED << "\n[ERROR] Invalid choice. Please try again.\n" << COLOR_RESET;
        }
        
        std::cout << COLOR_YELLOW << "\nPress Enter to continue..." << COLOR_RESET;
        std::cin.get();
    }
    
    return 0;
}

