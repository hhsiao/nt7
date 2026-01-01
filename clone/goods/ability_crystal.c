// This program is a part of NT MudLIB
// ab_crystal.c 能力水晶

#include <ansi.h>

inherit ITEM;

mapping dict = ([
    "axe": "斧",
    "bow": "弓",
    "sword": "劍",
    "blade": "刀",
    "club": "棍",
    "dagger": "匕首",
    "fork": "叉",
    "hammer": "錘",
    "staff": "杖",
    "throwing": "暗器",
    "whip": "鞭",
    "xsword": "簫",
    "head": "頭盔",
    "neck": "項鍊",
    "cloth": "衣服",
    "charm": "符文",
    "rings": "戒指",
    "armor": "護甲",
    "surcoat": "披風",
    "waist": "腰帶",
    "wrists": "護腕",
    "shield": "盾甲",
    "hands": "鐵掌",
    "boots": "靴子",
    "finger": "指套",
    "all": "所有類型"
    ]);

string to_chinese(string str) {
    if (! undefinedp(dict[str]))
        return dict[str];
    else
        return str;
}

void create() {
    set_name(HIM"能力水晶"NOR, ({ "ability crystal", "ability", "crystal" }) );
    set_weight(1);
    set("long", HIM "表面泛著粉色光芒的能力水晶，可以將自造裝備的鑲嵌寶石屬性、神器等級、強化效果\n"
        HIM "起靈及套裝效果儲存(store)起來，然後可以無損失注入(infuse)到新的簽名裝備上。\n" NOR);
    set("value", 50000);
    set("unit", "塊");
    //set("set_data", 1);
    set("autoload", 1);
    setup();
}

void init() {
    add_action("do_store", "store");
    add_action("do_infuse", "infuse");
}

int do_store(string arg) {
    object me, ob;
    mapping ultimate, magic, enchase, qianghua;
    mapping *insert;
    mixed qiling;
    string mod_name, mod_level;
    string type;
    int status;

    me = this_player();

    if(!arg || arg == "" )
        return notify_fail("你要儲存什麼裝備上的能力？\n");

    if(!objectp(ob = present(arg, me)) &&
        !objectp(ob = present(arg, environment(me))))
        return notify_fail("你身上和附近沒有這樣裝備啊。\n");

    if(!ob->is_item_make() )
        return notify_fail("能力水晶只可存儲自造裝備的能力。\n");

    if(!wizardp(me) && ob->item_owner() != query("id", me) )
        return notify_fail("這個，好象不屬於你吧，這樣不大合適。\n");

    if(query("equipped", ob) )
        return notify_fail("你先解除" + ob->name() + "的裝備再說！\n");

    if(!mapp(enchase = query("enchase", ob)) || !(insert = query("insert", ob)) )
        return notify_fail("能力水晶只能存儲鑲嵌過寶石的裝備屬性。\n");

    if(query("can_infuse") )
        return notify_fail("能力水晶已經儲存過能力，無法再存儲。\n");

    if(ob->is_weapon() )
        type = query("skill_type", ob);
    else
        type = query("armor_type", ob);

    set("can_infuse", type);

    set("combat", query("combat", ob));     // 10LV
    set("owner", query("owner", ob));
    set("forge", query("forge", ob));
    delete("combat", ob);
    delete("owner", ob);

    delete("forge", ob);

    ultimate = query("ultimate", ob);   // 上古、遠古
    set("ultimate", ultimate);
    delete("ultimate", ob);

    status = query("status", ob);   // 啟靈狀態
    set("status", status);
    set("status", 1, ob);
    qiling = query("qiling", ob);   // 啟靈屬性
    if(sizeof(qiling) )
        set("qiling", qiling);
    delete("qiling", ob);

    if(!undefinedp(enchase["mod_prop"]) )   // 套裝
    {
        mod_name = query("mod_name", ob);
        mod_level = query("mod_level", ob);
        set("mod_name", mod_name);
        set("mod_level", mod_level);
        delete("mod_name", ob);
        delete("mod_level", ob);
        delete("mod_mark", ob);
    }

    set("enchase", enchase);    // 鑲嵌
    set("insert", insert);
    delete("enchase", ob);
    delete("insert", ob);

    qianghua = query("qianghua", ob);   // 強化
    if(mapp(qianghua) && sizeof(qianghua) > 0 )
    {
        set("qianghua", qianghua);
        delete("qianghua", ob);
    }

    magic = query("magic", ob);     // 金木水火土屬性
    if(mapp(magic) && sizeof(magic) > 0 )
    {
        set("magic", magic);
        delete("magic", ob);
    }

    set("set_data", 1);

    ob->save();

    tell_object(me, HIC "你將" +ob->name() + HIC "的能力存儲到能力水晶成功。\n" NOR);
    return 1;
}

int do_infuse(string arg) {
    object me, ob;
    mapping data, prop, magic, enchase, qianghua;
    mapping *insert;
    mixed qiling;
    string *apply;
    string type;
    int i;

    me = this_player();

    if(!arg || arg == "" )
        return notify_fail("你要給什麼裝備註入能力？\n");

    if(!objectp(ob = present(arg, me)) &&
        !objectp(ob = present(arg, environment(me))))
        return notify_fail("你身上和附近沒有這樣裝備啊。\n");

    if(!ob->is_item_make() )
        return notify_fail("能力水晶只可給已簽名裝備註入能力。\n");

    if(!wizardp(me) && ob->item_owner() != query("id", me) )
        return notify_fail("這個，好象不屬於你吧，這樣不大合適。\n");

    if(query("equipped", ob) )
        return notify_fail("你先解除" + ob->name() + "的裝備再說！\n");

    enchase = query("enchase");
    if(!mapp(enchase) || sizeof(enchase) < 1 )
        return notify_fail("能力水晶沒有儲存過任何能力！\n");

    type = query("can_infuse");
    if(type != query("skill_type", ob) && type != query("armor_type", ob) )
        return notify_fail("能力水晶只能給"+to_chinese(type) + "注入能力。\n");

    /*
     * flute = enchase["flute"];
     * if( query("enchase/flute", ob) < flute )
     * return notify_fail(ob->name()+"的已開孔數必須不小於能力水晶中存儲能力的孔數("+flute+")！\n");
     */

    if(ob->is_weapon() )
        prop = copy(query("weapon_prop", ob));
    else
        prop = copy(query("armor_prop", ob));

    map_delete(prop, "damage");
    map_delete(prop, "unarmed_damage");
    map_delete(prop, "armor");

    set("combat", query("combat"), ob);     // 10LV
    set("owner", query("owner"), ob);
    set("forge", query("forge"), ob);

    if(mapp(data = query("ultimate")) )     // 上古、遠古
    {
        delete("ultimate", ob);
        set("ultimate", data, ob);
    }
    if(sizeof(prop) )
    {
        delete("rare", ob);     // 刪除原有提高的稀有屬性

        apply = keys(prop);
        if(query("ultimate/121", ob) )
        {
            for(i = 0;i<sizeof(apply);i++ )
            {
                prop[apply[i]] = prop[apply[i]] * 2;
                if(query("quality_level", ob) == 4 )
                {
                    if(sizeof(apply) == 1 )
                        prop[apply[i]] = prop[apply[i]] * 3;
                } else
                if(query("quality_level", ob) == 5 )
                {
                    if(sizeof(apply) == 1 )
                        prop[apply[i]] = prop[apply[i]] * 4;
                    else if(sizeof(apply) == 2 )
                        prop[apply[i]] = prop[apply[i]] * 2;
                } else
                if(query("quality_level", ob) == 6 )
                {
                    if(sizeof(apply) == 1 )
                        prop[apply[i]] = prop[apply[i]] * 16;
                    else if(sizeof(apply) == 2 )
                        prop[apply[i]] = prop[apply[i]] * 8;
                    else if(sizeof(apply) == 3 )
                        prop[apply[i]] = prop[apply[i]] * 4;
                    else
                        prop[apply[i]] = prop[apply[i]] * 2;
                }
            }
            set("rare/apply_prop", prop, ob);
        }
        else if(query("ultimate/105", ob) )
        {
            for(i = 0;i<sizeof(apply);i++ )
            {
                prop[apply[i]] = prop[apply[i]] * 2;
                if(query("quality_level", ob) == 4 )
                {
                    if(sizeof(apply) == 1 )
                        prop[apply[i]] = prop[apply[i]] * 2;
                } else
                if(query("quality_level", ob) == 5 )
                {
                    if(sizeof(apply) == 1 )
                        prop[apply[i]] = prop[apply[i]] * 3;
                    else if(sizeof(apply) == 2 )
                        prop[apply[i]] = prop[apply[i]] * 2;
                } else
                if(query("quality_level", ob) == 6 )
                {
                    if(sizeof(apply) == 1 )
                        prop[apply[i]] = prop[apply[i]] * 8;
                    else if(sizeof(apply) == 2 )
                        prop[apply[i]] = prop[apply[i]] * 4;
                    else if(sizeof(apply) == 3 )
                        prop[apply[i]] = prop[apply[i]] * 3;
                    else
                        prop[apply[i]] = prop[apply[i]] * 2;
                }
            }
            set("rare/apply_prop", prop, ob);
        }
        else if(query("ultimate/87", ob) )
        {
            if (ob->is_weapon() || ob->is_unarmed_weapon())
            {
                for(i = 0;i<sizeof(apply);i++ )
                {
                    prop[apply[i]] = prop[apply[i]] * 3 / 2;
                    if(query("quality_level", ob) == 4 )
                    {
                        if(sizeof(apply) == 1 )
                            prop[apply[i]] = prop[apply[i]] * 2;
                    } else
                    if(query("quality_level", ob) == 5 )
                    {
                        if(sizeof(apply) == 1 )
                            prop[apply[i]] = prop[apply[i]] * 3;
                        else if(sizeof(apply) == 2 )
                            prop[apply[i]] = prop[apply[i]] * 2;
                    } else
                    if(query("quality_level", ob) == 6 )
                    {
                        if(sizeof(apply) == 1 )
                            prop[apply[i]] = prop[apply[i]] * 8;
                        else if(sizeof(apply) == 2 )
                            prop[apply[i]] = prop[apply[i]] * 4;
                        else if(sizeof(apply) == 3 )
                            prop[apply[i]] = prop[apply[i]] * 3;
                        else
                            prop[apply[i]] = prop[apply[i]] * 2;
                    }
                }
            }
            else
            {
                for(i = 0;i<sizeof(apply);i++ )
                {
                    prop[apply[i]] = prop[apply[i]] * 2;
                    if(query("quality_level", ob) == 4 )
                    {
                        if(sizeof(apply) == 1 )
                            prop[apply[i]] = prop[apply[i]] * 2;
                    } else
                    if(query("quality_level", ob) == 5 )
                    {
                        if(sizeof(apply) == 1 )
                            prop[apply[i]] = prop[apply[i]] * 3;
                        else if(sizeof(apply) == 2 )
                            prop[apply[i]] = prop[apply[i]] * 2;
                    } else
                    if(query("quality_level", ob) == 6 )
                    {
                        if(sizeof(apply) == 1 )
                            prop[apply[i]] = prop[apply[i]] * 8;
                        else if(sizeof(apply) == 2 )
                            prop[apply[i]] = prop[apply[i]] * 4;
                        else if(sizeof(apply) == 3 )
                            prop[apply[i]] = prop[apply[i]] * 3;
                        else
                            prop[apply[i]] = prop[apply[i]] * 2;
                    }
                }
            }
            set("rare/apply_prop", prop, ob);
        }
        else if(query("ultimate/69", ob) )
        {
            for(i = 0;i<sizeof(apply);i++ )
            {
                prop[apply[i]] = prop[apply[i]] * 3 / 2;
                if(query("quality_level", ob) == 4 )
                {
                    if(sizeof(apply) == 1 )
                        prop[apply[i]] = prop[apply[i]] * 2;
                } else
                if(query("quality_level", ob) == 5 )
                {
                    if(sizeof(apply) == 1 )
                        prop[apply[i]] = prop[apply[i]] * 3;
                    else if(sizeof(apply) == 2 )
                        prop[apply[i]] = prop[apply[i]] * 2;
                } else
                if(query("quality_level", ob) == 6 )
                {
                    if(sizeof(apply) == 1 )
                        prop[apply[i]] = prop[apply[i]] * 8;
                    else if(sizeof(apply) == 2 )
                        prop[apply[i]] = prop[apply[i]] * 4;
                    else if(sizeof(apply) == 3 )
                        prop[apply[i]] = prop[apply[i]] * 3;
                    else
                        prop[apply[i]] = prop[apply[i]] * 2;
                }
            }
            set("rare/apply_prop", prop, ob);
        }
    }

    set("enchase", enchase, ob);    // 鑲嵌
    insert = query("insert");
    set("insert", insert, ob);
    qianghua = query("qianghua");   // 強化
    if(mapp(qianghua) && sizeof(qianghua) )
        set("qianghua", qianghua, ob);

    magic = query("magic");     // 金木水火土屬性
    if(mapp(magic) && sizeof(magic) )
        set("magic", magic, ob);

    set("status", query("status"), ob);
    qiling = query("qiling");   // 啟靈
    {
        set("qiling", qiling, ob);
        if(query("weapon_prop/damage", ob) )
            set("qiling/apply_prop/damage", query("weapon_prop/damage", ob) * 2, ob);
        if(query("armor_prop/unarmed_damage", ob) )
            set("qiling/apply_prop/unarmed_damage", query("armor_prop/unarmed_damage", ob) * 2, ob);
        if(query("armor_prop/armor", ob) )
            set("qiling/apply_prop/armor", query("armor_prop/armor", ob) * 2, ob);
    }

    if(query("mod_name") )  // 套裝
    {
        set("mod_name", query("mod_name"), ob);
        set("mod_mark", base_name(ob), ob);
    }

    if(query("mod_level") )
        set("mod_level", query("mod_level"), ob);

    ob->save();

    tell_object(me, HIC "你將能力水晶中的能力注入" +ob->name() + HIC "成功。\n" NOR);
    destruct(this_object());
    return 1;
}

string extra_long() {
    mapping enchase, qianghua, qiling;
    string *apply, str, type;
    mixed value;
    int i;

    str = sprintf(YEL "\n物品屬性 : 特殊物<能力水晶>，重量%d克，下線%s丟失\n" NOR,
        this_object()->query_weight(),
        (this_object()->query_autoload() || query("autoload")) ? "不" : "" );

    if(mapp(enchase = copy(query("enchase/apply_prop"))) )
    {
        type = query("can_infuse");
        str += sprintf(HIK "附魔裝備 : %s(%s)\n" NOR, to_chinese(type), type);
        apply = keys(enchase);
        for (i = 0; i<sizeof(apply); i++)
        {
            value = enchase[apply[i]];
            str += HIK "擁有屬性" NOR " : ";
            str += HIB + EQUIPMENT_D->chinese(apply[i], value) + NOR + "\n";
        }
    }

    if(mapp(enchase = query("enchase/mod_prop")) )
    {
        apply = keys(enchase);
        for (i = 0; i<sizeof(apply); i++)
        {
            value = enchase[apply[i]];
            str += HIK "擁有屬性" NOR " : ";
            str += HIB + EQUIPMENT_D->chinese(apply[i], value) + NOR + "\n";
        }
    }

    if(mapp(qianghua = query("qianghua/apply_prop")) )
    {
        apply = keys(qianghua);
        for (i = 0; i<sizeof(apply); i++)
        {
            value = qianghua[apply[i]];
            str += HIK "擁有屬性" NOR " : ";
            str += HIB + EQUIPMENT_D->chinese(apply[i], value) + NOR + "\n";
        }
    }

    if(mapp(qiling = query("qiling/apply_prop")) )
    {
        apply = keys(qiling);
        for (i = 0; i<sizeof(apply); i++)
        {
            value = qiling[apply[i]];
            str += HIK "擁有屬性" NOR " : ";
            str += HIB + EQUIPMENT_D->chinese(apply[i], value) + NOR + "\n";
        }
    }

    return str;
}

string query_name() { return HIM"能力水晶"NOR; }
