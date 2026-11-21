"""TDLib's message entities, one module per section of their upstream file.

This module holds what `td/telegram/MessageEntity.h` declares, so code outside the
package imports those names from here, whichever module of the package defines them.
"""

from tdlib_oracle.tdlib.message_entity.conversion import (
    get_formatted_text,
    get_input_message_entities,
    get_message_entities,
    get_text_entities_object,
    get_text_entity_object,
    get_text_entity_type_object,
)
from tdlib_oracle.tdlib.message_entity.entity import (
    TYPE,
    FormattedText,
    MessageEntity,
    order,
)
from tdlib_oracle.tdlib.message_entity.finding import (
    find_bank_card_numbers,
    find_bot_commands,
    find_cashtags,
    find_entities,
    find_hashtags,
    find_mentions,
    find_tg_urls,
    find_ton_addresses,
    find_urls,
    is_email_address,
)
from tdlib_oracle.tdlib.message_entity.fixing import (
    fix_entities,
    fix_formatted_text,
    remove_empty_entities,
)
from tdlib_oracle.tdlib.message_entity.html import parse_html

__all__ = [
    "TYPE",
    "FormattedText",
    "MessageEntity",
    "find_bank_card_numbers",
    "find_bot_commands",
    "find_cashtags",
    "find_entities",
    "find_hashtags",
    "find_mentions",
    "find_tg_urls",
    "find_ton_addresses",
    "find_urls",
    "fix_entities",
    "fix_formatted_text",
    "get_formatted_text",
    "get_input_message_entities",
    "get_message_entities",
    "get_text_entities_object",
    "get_text_entity_object",
    "get_text_entity_type_object",
    "is_email_address",
    "order",
    "parse_html",
    "remove_empty_entities",
]
