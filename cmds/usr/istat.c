// This program is a part of NT MudLIB
// stats cmds - refactored with proper argument parsing + GMCP

#include <ansi.h>
#include <mudlib.h>
#include <command.h>

inherit F_CLEAN_UP;

// ─── Supported flags ───
// Each maps to a query function suffix: query_<source>_buff()
#define VALID_FLAGS ({ "-jingmai", "-yuanshen", "-ability", "-skillmix", "-equipment", "-talent" })

// Display title per source
mapping SOURCE_TITLES = ([
    "all":       "各附加屬性",
    "jingmai":   "經脈附加屬性",
    "yuanshen":  "元神附加屬性",
    "skillmix":  "技能組合附加屬性",
    "ability":   "能力進階附加屬性",
    "equipment": "裝備附加屬性",
    "talent":    "天賦附加屬性",
]);

// ─── Parse arguments: extract flag and target name ───
// Returns ({ string source, string target_name })
// source = "all" | "jingmai" | "yuanshen" | "ability" | "skillmix" | "equipment" | "talent"
// target_name = 0 (self) or player id string
private mixed *parse_args(string arg) {
    string source = "all";
    string target = 0;

    if (!arg || arg == "")
        return ({ source, target });

    // Split into words
    string *words = explode(arg, " ");
    string *remaining = ({});

    foreach (string w in words) {
        if (member_array(w, VALID_FLAGS) != -1)
            source = w[1..];  // strip leading "-"
        else
            remaining += ({ w });
    }

    if (sizeof(remaining) > 0)
        target = implode(remaining, " ");

    return ({ source, target });
}

// ─── Resolve target object from name ───
private object resolve_target(object me, string target_name) {
    object ob;

    ob = present(target_name, environment(me));
    if (ob && ob->is_character() && me->visible(ob))
        return ob;

    ob = find_player(target_name);
    if (ob && ob->is_character() && me->visible(ob))
        return ob;

    ob = find_living(target_name);
    if (ob && ob->is_character() && me->visible(ob))
        return ob;

    return 0;
}

// ─── Generic buff query: calls ob->query_<source>_buff(key) ───
private mixed qbuff(object ob, string source, string key) {
    return call_other(ob, "query_" + source + "_buff", key);
}

// ─── Build the buff display string ───
private string build_buff_display(object me, object ob, string source) {
    string sp = "";
    string title = SOURCE_TITLES[source] || "附加屬性";
    string who = (ob == me) ? "你" : ob->name(1);
    string who2 = (ob == me) ? "你" : ob->name();

    sp += HIM + who + "目前的" + title + "效果一覽\n" NOR;

    // ── 天賦加成 ──
    sp += HIC "≡" HIY "------------------------------==天賦加成==------------------------------" HIC "≡\n\n" NOR;
    sp += sprintf(HIC "【臂力附加】" HIG " %9d / %-9d"
        HIC "【悟性附加】" HIG " %9d / %d\n"
        HIC "【根骨附加】" HIG " %9d / %-9d"
        HIC "【身法附加】" HIG " %9d / %d\n\n",
        qbuff(ob, source, "str"), 2000,
        qbuff(ob, source, "int"), 2000,
        qbuff(ob, source, "con"), 2000,
        qbuff(ob, source, "dex"), 2000);

    // ── 上限加成 ──
    sp += HIC "≡" HIY "------------------------------------------------------------------------" HIC "≡\n" NOR;
    sp += HIC "≡" HIY "------------------------------==上限加成==------------------------------" HIC "≡\n\n" NOR;
    sp += sprintf(HIC "【潛能上限】" HIM " %9d / %-9d"
        HIC "【體會上限】" HIM " %9d / %d\n"
        HIC "【內力上限】" HIM " %9d / %-9d"
        HIC "【精力上限】" HIM " %9d / %d\n"
        HIC "【氣血上限】" HIM " %9d / %-9d"
        HIC "【精氣上限】" HIM " %9d / %d\n\n",
        qbuff(ob, source, "max_potential"), 10000000,
        qbuff(ob, source, "max_experience"), 10000000,
        qbuff(ob, source, "max_neili"), 2000000,
        qbuff(ob, source, "max_jingli"), 1000000,
        qbuff(ob, source, "max_qi"), 2000000,
        qbuff(ob, source, "max_jing"), 1000000);

    // ── 練功加成 ──
    sp += HIC "≡" HIY "------------------------------------------------------------------------" HIC "≡\n" NOR;
    sp += HIC "≡" HIY "------------------------------==練功加成==------------------------------" HIC "≡\n\n" NOR;
    sp += sprintf(HIC "【研究次數】" HIY " %9d / %-9d"
        HIC "【研究效果】" HIY " %9s / %s\n"
        HIC "【練習次數】" HIY " %9d / %-9d"
        HIC "【練習效果】" HIY " %9s / %s\n"
        HIC "【學習次數】" HIY " %9d / %-9d"
        HIC "【學習效果】" HIY " %9s / %s\n"
        HIC "【汲取消耗】" HIY " %9d / %-9d"
        HIC "【汲取效果】" HIY " %9s / %s\n\n",
        qbuff(ob, source, "research_times"), 2000,
        qbuff(ob, source, "research_effect") + "%", "2000%",
        qbuff(ob, source, "practice_times"), 2000,
        qbuff(ob, source, "practice_effect") + "%", "2000%",
        qbuff(ob, source, "learn_times"), 2000,
        qbuff(ob, source, "learn_effect") + "%", "2000%",
        qbuff(ob, source, "derive_times"), 2000,
        qbuff(ob, source, "derive_effect") + "%", "2000%");

    // ── 五行加成 ──
    sp += HIC "≡" HIY "------------------------------------------------------------------------" HIC "≡\n" NOR;
    sp += HIC "≡" HIY "------------------------------==五行加成==------------------------------" HIC "≡\n\n" NOR;
    sp += sprintf(RED "【毒 傷 害】" RED " %9s / %-9s"
        RED "【抗    毒】" RED " %9s / %s\n"
        RED "【魔 傷 害】" RED " %9s / %-9s"
        RED "【抗    魔】" RED " %9s / %s\n"
        RED "【金 傷 害】" RED " %9s / %-9s"
        RED "【抗    金】" RED " %9s / %s\n"
        RED "【木 傷 害】" RED " %9s / %-9s"
        RED "【抗    木】" RED " %9s / %s\n"
        RED "【水 傷 害】" RED " %9s / %-9s"
        RED "【抗    水】" RED " %9s / %s\n"
        RED "【火 傷 害】" RED " %9s / %-9s"
        RED "【抗    火】" RED " %9s / %s\n"
        RED "【土 傷 害】" RED " %9s / %-9s"
        RED "【抗    土】" RED " %9s / %s\n\n",
        qbuff(ob, source, "add_poison") + "%", "100%", qbuff(ob, source, "reduce_poison") + "%", "100%",
        qbuff(ob, source, "add_magic") + "%", "100%", qbuff(ob, source, "reduce_magic") + "%", "100%",
        qbuff(ob, source, "add_metal") + "%", "100%", qbuff(ob, source, "reduce_metal") + "%", "100%",
        qbuff(ob, source, "add_wood") + "%", "100%", qbuff(ob, source, "reduce_wood") + "%", "100%",
        qbuff(ob, source, "add_water") + "%", "100%", qbuff(ob, source, "reduce_water") + "%", "100%",
        qbuff(ob, source, "add_fire") + "%", "100%", qbuff(ob, source, "reduce_fire") + "%", "100%",
        qbuff(ob, source, "add_earth") + "%", "100%", qbuff(ob, source, "reduce_earth") + "%", "100%");

    // ── 狀態恢復 ──
    sp += HIC "≡" HIY "------------------------------------------------------------------------" HIC "≡\n" NOR;
    sp += HIC "≡" HIY "------------------------------==狀態恢復==------------------------------" HIC "≡\n\n" NOR;
    sp += sprintf(HIB "【偷取內力】" HIB " %9s / %-9s"
        HIB "【偷取生命】" HIB " %9s / %s\n\n",
        qbuff(ob, source, "leech_neili") + "%", "90%",
        qbuff(ob, source, "leech_qi") + "%", "90%");

    // ── 戰鬥加成 ──
    sp += HIC "≡" HIY "------------------------------------------------------------------------" HIC "≡\n" NOR;
    sp += HIC "≡" HIY "------------------------------==戰鬥加成==------------------------------" HIC "≡\n\n" NOR;
    sp += sprintf(WHT "【攻擊等級】" HIW " %9d / %-9d" NOR
        WHT "【防禦等級】" HIW " %9d / %d\n" NOR
        WHT "【躲閃等級】" HIW " %9d / %-9d" NOR
        WHT "【招架等級】" HIW " %9d / %d\n" NOR
        WHT "【絕招命中】" HIW " %9s / %-9s" NOR
        WHT "【絕招防禦】" HIW " %9s / %s\n" NOR
        WHT "【兵器傷害】" HIG " %9d / %-9d" NOR
        WHT "【空手傷害】" HIG " %9d / %d\n" NOR
        WHT "【絕招傷害】" HIG " %9s / %-9s" NOR
        WHT "【戰鬥保護】" HIG " %9d / %d\n" NOR
        WHT "【忽視招架】" HIY " %9s / %-9s" NOR
        WHT "【忽視躲閃】" HIY " %9s / %s\n" NOR
        WHT "【忽視特攻】" HIY " %9s / %-9s" NOR
        WHT "【忽視內防】" HIY " %9s / %s\n\n" NOR,
        qbuff(ob, source, "attack"), 9000,
        qbuff(ob, source, "defense"), 9000,
        qbuff(ob, source, "dodge"), 9000,
        qbuff(ob, source, "parry"), 9000,
        qbuff(ob, source, "ap_power") + "%", "120%",
        qbuff(ob, source, "dp_power") + "%", "120%",
        qbuff(ob, source, "damage"), 200000,
        qbuff(ob, source, "unarmed_damage"), 200000,
        qbuff(ob, source, "da_power") + "%", "120%",
        qbuff(ob, source, "armor"), 200000,
        qbuff(ob, source, "avoid_parry") + "%", "90%",
        qbuff(ob, source, "avoid_dodge") + "%", "90%",
        qbuff(ob, source, "avoid_attack") + "%", "90%",
        qbuff(ob, source, "avoid_force") + "%", "90%");

    // ── 高級屬性 ──
    sp += HIC "≡" HIY "------------------------------------------------------------------------" HIC "≡\n" NOR;
    sp += HIC "≡" HIY "------------------------------==高級屬性==------------------------------" HIC "≡\n\n" NOR;
    sp += sprintf(HIW "【化解忙亂】" HIM " %9d / %-9d"
        HIW "【尋 寶 率】" HIM " %9s / %s\n"
        HIW "【雙倍傷害】" CYN " %9s / %-9s"
        HIW "【傷轉內力】" CYN " %9s / %s\n"
        HIW "【致    盲】" CYN " %9s / %-9s"
        HIW "【忽視致盲】" CYN " %9s / %s\n"
        HIW "【穿透破甲】" CYN " %9s / %-9s"
        HIW "【百毒不侵】" CYN " %9s / %s\n"
        HIW "【戰神附體】" CYN " %9s / %-9s\n\n",
        qbuff(ob, source, "reduce_busy"), 90,
        qbuff(ob, source, "magic_find") + "%", "300%",
        qbuff(ob, source, "double_damage") + "%", "200%",
        qbuff(ob, source, "qi_abs_neili") + "%", "90%",
        qbuff(ob, source, "add_blind") + "%", "90%",
        qbuff(ob, source, "avoid_blind") + "%", "90%",
        qbuff(ob, source, "through_armor") + "%", "90%",
        qbuff(ob, source, "avoid_poison") + "%", "100%",
        qbuff(ob, source, "full_self") + "%", "90%");

    // ── 終極屬性 ──
    sp += HIC "≡" HIY "------------------------------------------------------------------------" HIC "≡\n" NOR;
    sp += HIC "≡" HIY "------------------------------==終極屬性==------------------------------" HIC "≡\n\n" NOR;
    sp += sprintf(HIY "【冰    凍】" HIM " %9s / %-9s"
        HIY "【忽視冰凍】" HIM " %9s / %s\n"
        HIY "【遺    忘】" HIM " %9s / %-9s"
        HIY "【忽視遺忘】" HIM " %9s / %s\n"
        HIY "【忙    亂】" HIM " %9d / %-9d"
        HIY "【忽視忙亂】" HIM " %9s / %s\n"
        HIY "【虛    弱】" HIM " %9s / %-9s"
        HIY "【忽視虛弱】" HIM " %9s / %s\n"
        HIY "【追加傷害】" HIM " %9s / %-9s"
        HIY "【化解傷害】" HIM " %9s / %s\n"
        HIY "【傷害反噬】" HIM " %9s / %-9s"
        HIY "【浴血重生】" HIM " %9s / %s\n"
        HIY "【致命一擊】" HIM " %9s / %-9s"
        HIY "【提升技能】" HIM " %9d / %d\n\n",
        qbuff(ob, source, "add_freeze") + "%", "90%", qbuff(ob, source, "avoid_freeze") + "%", "90%",
        qbuff(ob, source, "add_forget") + "%", "90%", qbuff(ob, source, "avoid_forget") + "%", "90%",
        qbuff(ob, source, "add_busy"), 90, qbuff(ob, source, "avoid_busy") + "%", "90%",
        qbuff(ob, source, "add_weak") + "%", "90%", qbuff(ob, source, "avoid_weak") + "%", "90%",
        qbuff(ob, source, "add_damage") + "%", "200%",
        qbuff(ob, source, "reduce_damage") + "%", "90%",
        qbuff(ob, source, "counter_damage") + "%", "90%", qbuff(ob, source, "avoid_die") + "%", "90%",
        qbuff(ob, source, "fatal_blow") + "%", "90%", qbuff(ob, source, "add_skill"), 1200);

    // ── 王者歸來 ──
    sp += HIC "≡" HIY "------------------------------==王者歸來==------------------------------" HIC "≡\n\n" NOR;
    sp += sprintf(HIG + who2 + HIG "在%s裡已經歷練了 " NOR + HIC "%s\n" NOR,
        LOCAL_MUD_NAME(), time_period(query("online_time", ob)));

    if (MEMBER_D->is_valid_member(ob))
        sp += sprintf(HIG + who2 + HIG "可用來離線練功時間還有 " NOR + HIY "無限制\n" NOR);
    else
    {
        if (query("online_time", ob) / 3 < query("offline_time", ob))
            set("offline_time", query("online_time", ob) / 3, ob);
        sp += sprintf(HIG + who2 + HIG "可用來離線練功時間還有 " NOR + HIY "%s\n" NOR,
            time_period(query("online_time", ob) / 3 - query("offline_time", ob)));
    }

    // Only show quit_save for the "all" (no flag) view
    if (source == "all")
        sp += sprintf(HIG + who2 + HIG "下線保留物品時間還剩下 " NOR + HIW "%s\n" NOR,
            (query("srv/quit_save", ob) - time()) > 0 ? time_period(query("srv/quit_save", ob) - time()) : "零秒");

    sp += sprintf(HIG + who2 + HIG "今天的雙倍經驗時間還餘 " NOR + HIW "%s\n" NOR,
        time_period(query("time_reward/quest", ob)));
    sp += sprintf(HIG + who2 + HIG "今天的高效練功時間還餘 " NOR + HIM "%s\n" NOR,
        time_period(query("time_reward/study", ob)));

    return sp;
}

int main(object me, string arg) {
    object ob;
    mixed *parsed;
    string source, target;

    seteuid(getuid(me));

    if (!wizardp(me) && time() - query_temp("last_stats", me) < 5)
        return notify_fail("系統氣喘噓地嘆道：慢慢來 ....\n");

    set_temp("last_stats", time(), me);
    MYGIFT_D->check_mygift(me, "newbie_mygift/istat");

    // Parse arguments cleanly
    parsed = parse_args(arg);
    source = parsed[0];
    target = parsed[1];

    // Resolve target
    if (target) {
        if (wizardp(me) || query("couple/child_id", me)) {
            ob = resolve_target(me, target);

            if (!ob)
                return notify_fail("你要察看誰的狀態？\n");

            if (!wizardp(me) && query("couple/child_id", me) != query("id", ob))
                return notify_fail("你要察看誰的狀態？\n");
        } else
            return notify_fail("只有巫師能察看別人的狀態。\n");
    } else
        ob = me;

    // Build and display
    me->start_more(build_buff_display(me, ob, source));

    return 1;
}

int help(object me) {
    write(@HELP
指令格式：istat [-jingmai] [-yuanshen] [-ability] [-skillmix] [-equipment] [-talent]
          istat [-jingmai] [-yuanshen] [-ability] [-skillmix] [-equipment] [-talent] <對象名稱>  （巫師專用）

這個指令可以顯示你或指定對象的各種附加狀態等數值。

不加參數時顯示所有來源的合計附加屬性（query_all_buff）。
加參數時顯示單一來源的附加屬性。參數位置不限。

範例：
  istat                     - 查看自己的總附加屬性
  istat -jingmai            - 查看自己的經脈附加屬性
  istat -talent             - 查看自己的天賦附加屬性
  istat -jingmai player_id  - 巫師查看他人的經脈屬性
  istat player_id -jingmai  - 同上，參數順序不限

HELP);
    return 1;
}
