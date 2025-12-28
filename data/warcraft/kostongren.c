// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("美麗中國夢[2;37;0m[2;37;0m", ({"kostongrenpet"}));        
        set("gender", "男性");                
        set("long", "$HIB$倉庫銅人[2;37;0m
它是銅人倉庫的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kostongren");
        set("owner_name", "銅人倉庫");
        set_temp("owner", "kostongren");
        set_temp("owner_name", "銅人倉庫");
        ::setup();
}
