// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[37m關關[2;37;0m[2;37;0m", ({"kwankwan"}));        
        set("gender", "男性");                
        set("long", "關關[2;37;0m
它是奴才一號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kwanone");
        set("owner_name", "奴才一號");
        set_temp("owner", "kwanone");
        set_temp("owner_name", "奴才一號");
        ::setup();
}
