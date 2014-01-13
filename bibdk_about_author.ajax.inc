<?php

/**
 * Return json object from ajax call
 */
function bibdk_about_author_ajax_get_about_author(){
  $data['query'] = $_REQUEST['query'];

  if ( empty($_REQUEST['query']) ) {
    $data['error'] = t('bibdk_about_author_empty_query_error');
  }
  else {
    $result = bibdk_about_author_get_about_author($data['query']);
  }

  if ( empty($result) ){
    $data['error'] = t('bibdk_about_author_no_records');
  }
  else {
    $data['list'] = bibdk_about_author_get_link_list_view($result);
  }
  drupal_json_output($data);
}
