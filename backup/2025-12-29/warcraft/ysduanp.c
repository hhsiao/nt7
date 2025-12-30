// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m蘋果[2;37;0m[2;37;0m", ({"apple"}));        
        set("gender", "男性");                
        set("long", "這是蘋果的坐騎[2;37;0m
它是彩韻亨菲的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ysduanp");
        set("owner_name", "彩韻亨菲");
        set_temp("owner", "ysduanp");
        set_temp("owner_name", "彩韻亨菲");
        ::setup();
}
