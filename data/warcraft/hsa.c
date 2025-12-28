// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;37m飛[31m龍[1;32m在[34m天[2;37;0m[2;37;0m", ({"flydragon"}));        
        set("gender", "女性");                
        set("long", "哈哈[2;37;0m
它是風飛揚的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hsa");
        set("owner_name", "風飛揚");
        set_temp("owner", "hsa");
        set_temp("owner_name", "風飛揚");
        ::setup();
}
