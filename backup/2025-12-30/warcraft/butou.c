// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m爪電[1;33m飛黃[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這西域神駒渾身黃金緞子似的，只有四蹄黑色，絕影追光。[2;37;0m
它是邢捕頭的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "butou");
        set("owner_name", "邢捕頭");
        set_temp("owner", "butou");
        set_temp("owner_name", "邢捕頭");
        ::setup();
}
