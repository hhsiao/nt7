// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小馬[2;37;0m[2;37;0m", ({"xiaoma"}));        
        set("gender", "女性");                
        set("long", "小馬[2;37;0m
它是華拉拉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hxxb");
        set("owner_name", "華拉拉");
        set_temp("owner", "hxxb");
        set_temp("owner_name", "華拉拉");
        ::setup();
}
