// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;33m葵花寶典[2;37;0m[2;37;0m", ({"ning"}));
        set("gender", "女性");
        set("long", "哈哈[2;37;0m
�???�嶽不群的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ybq");
        set("owner_name", "???不群");
        set_temp("owner", "ybq");
        set_temp("owner_name", "???不群");
        ::setup();
}
