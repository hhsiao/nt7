// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m大美人來啦[2;37;0m[2;37;0m", ({"meiren"}));        
        set("gender", "女性");                
        set("long", "很風騷的美人[2;37;0m
它是慕容美孃的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lmurong");
        set("owner_name", "慕容美娘");
        set_temp("owner", "lmurong");
        set_temp("owner_name", "慕容美娘");
        ::setup();
}
