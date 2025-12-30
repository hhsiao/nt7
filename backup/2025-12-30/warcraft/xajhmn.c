// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m旺財[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "這是一隻麒麟幼獸？或者就是一條土狗？就當是土狗吧，狗名旺財！[2;37;0m
它是鴻鈞的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xajhmn");
        set("owner_name", "鴻鈞");
        set_temp("owner", "xajhmn");
        set_temp("owner_name", "鴻鈞");
        ::setup();
}
