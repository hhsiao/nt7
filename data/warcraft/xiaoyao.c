// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m斯太爾[2;37;0m[2;37;0m", ({"coco"}));        
        set("gender", "女性");                
        set("long", "斯太爾[2;37;0m
它是逍遙的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xiaoyao");
        set("owner_name", "逍遙");
        set_temp("owner", "xiaoyao");
        set_temp("owner_name", "逍遙");
        ::setup();
}
