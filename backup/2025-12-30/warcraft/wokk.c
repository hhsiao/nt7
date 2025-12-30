// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m叫花雞[2;37;0m[2;37;0m", ({"wok"}));        
        set("gender", "女性");                
        set("long", "叫花雞!!![2;37;0m
它是夜爾爾的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wokk");
        set("owner_name", "夜爾爾");
        set_temp("owner", "wokk");
        set_temp("owner_name", "夜爾爾");
        ::setup();
}
