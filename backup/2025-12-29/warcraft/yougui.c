// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m青見[2;37;0m[2;37;0m", ({"zzzz"}));        
        set("gender", "女性");                
        set("long", "長得再靚也是我醜的坐騎[2;37;0m
它是酉鬼的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yougui");
        set("owner_name", "酉鬼");
        set_temp("owner", "yougui");
        set_temp("owner_name", "酉鬼");
        ::setup();
}
