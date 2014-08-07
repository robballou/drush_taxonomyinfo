<?php

/**
 * Implements hook_drush_command().
 *
 * Register the typeinfo command(s)
 */
function taxonomyinfo_drush_command() {
  $commands = array();

  $commands['taxonomyinfo-vocab-list'] = array(
    'callback' => 'drush_taxonomyinfo_vocab',
    'description' => 'Show vocabularies',
    'aliases' => array('tvl'),
    'examples' => array(
      'drush taxonomyinfo-vocab-list' => 'List vocabularies',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $commands['taxonomyinfo-term-list'] = array(
    'callback' => 'drush_taxonomyinfo_terms',
    'description' => 'Show terms in a vocabulary',
    'aliases' => array('ttl'),
    'examples' => array(
      'drush taxonomyinfo-term-list [vocabualary name]' => 'List all terms for a vocabulary',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $commands;
}

/**
 * Log the vocabulary info
 *
 * @see drush_taxonomyinfo_vocab
 */
function drush_taxonomyinfo_process_vocab($vocab) {
  return array($vocab->vid, $vocab->machine_name, $vocab->name);
}

/**
 * List fields in an entity/bundle
 *
 * @param mixed $vocab
 *   The vocabulary name or vid
 */
function drush_taxonomyinfo_terms($vocab) {
}

/**
 * List all vocabularies
 */
function drush_taxonomyinfo_vocab() {
  $vocabs = taxonomy_get_vocabularies();
  $vocab_info = array_map('drush_taxonomyinfo_log_vocab', $vocabs);
  return drush_print_table($vocab_info);
}
