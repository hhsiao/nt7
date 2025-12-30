// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m傻龍[2;37;0m[2;37;0m", ({"shalong"}));        
        set("gender", "男性");                
        set("long", "傻呼呼的龍[2;37;0m
它是讀者無聊的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "reader");
        set("owner_name", "讀者無聊");
        set_temp("owner", "reader");
        set_temp("owner_name", "讀者無聊");
        ::setup();
}
