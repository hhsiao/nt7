// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m呻吟的[1;35m蒼井空[2;37;0m[2;37;0m", ({"kong"}));        
        set("gender", "女性");                
        set("long", "正在呻吟中的蒼井空......[2;37;0m
它是王者歸來的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "mudnt");
        set("owner_name", "王者歸來");
        set_temp("owner", "mudnt");
        set_temp("owner_name", "王者歸來");
        ::setup();
}
