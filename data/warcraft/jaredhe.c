// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小四[2;37;0m[2;37;0m", ({"xiaosi"}));        
        set("gender", "男性");                
        set("long", "看起來雄壯異常[2;37;0m
它是火鍋年糕的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "jaredhe");
        set("owner_name", "火鍋年糕");
        set_temp("owner", "jaredhe");
        set_temp("owner_name", "火鍋年糕");
        ::setup();
}
