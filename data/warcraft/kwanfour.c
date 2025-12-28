// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m關關[2;37;0m[2;37;0m", ({"kwankwan"}));        
        set("gender", "男性");                
        set("long", "一隻關關[2;37;0m
它是奴才四號的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "kwanfour");
        set("owner_name", "奴才四號");
        set_temp("owner", "kwanfour");
        set_temp("owner_name", "奴才四號");
        ::setup();
}
