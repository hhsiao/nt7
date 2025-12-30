// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("逼[2;37;0m[2;37;0m", ({"aaabbb"}));        
        set("gender", "女性");                
        set("long", "逼[2;37;0m
它是龍斬刀的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "longzd");
        set("owner_name", "龍斬刀");
        set_temp("owner", "longzd");
        set_temp("owner_name", "龍斬刀");
        ::setup();
}
