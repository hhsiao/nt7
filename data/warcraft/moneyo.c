// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m齊玲[2;37;0m[2;37;0m", ({"moneyaa"}));        
        set("gender", "男性");                
        set("long", "齊玲[2;37;0m
它是錢大通的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "moneyo");
        set("owner_name", "錢大通");
        set_temp("owner", "moneyo");
        set_temp("owner_name", "錢大通");
        ::setup();
}
