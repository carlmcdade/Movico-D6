<?php
/**
 * Process variables for mvc-template.tpl.php
 *
 * Most themes utilize their own copy of page.tpl.php. The default is located
 * inside "modules/system/page.tpl.php". Look in there for the full list of
 * variables.
 *
 * Uses the arg() function to generate a series of page template suggestions
 * based on the current path.
 *
 * Any changes to variables in this preprocessor should also be changed inside
 * template_preprocess_maintenance_page() to keep all them consistent.
 *
 * The $variables array contains the following arguments:
 * - $content
 * - $show_blocks
 *
 * @see page.tpl.php
 */
 
 class drupal_env {
    function drupal_variables(&$variables) {
      // Add favicon
      if (theme_get_setting('toggle_favicon')) {
        drupal_set_html_head('<link rel="shortcut icon" href="'. check_url(theme_get_setting('favicon')) .'" type="image/x-icon" />');
      }
    
      global $theme;
      // Populate all block regions.
      $regions = system_region_list($theme);
      // Load all region content assigned via blocks.
      foreach (array_keys($regions) as $region) {
        // Prevent left and right regions from rendering blocks when 'show_blocks' == FALSE.
        if (!(!$variables['show_blocks'] && ($region == 'left' || $region == 'right'))) {
          $blocks = theme('blocks', $region);
        }
        else {
          $blocks = '';
        }
        // Assign region to a region variable.
        isset($variables[$region]) ? $variables[$region] .= $blocks : $variables[$region] = $blocks;
      }
    
      // Set up layout variable.
      $variables['layout'] = 'none';
      if (!empty($variables['left'])) {
        $variables['layout'] = 'left';
      }
      if (!empty($variables['right'])) {
        $variables['layout'] = ($variables['layout'] == 'left') ? 'both' : 'right';
      }
    
      // Set mission when viewing the frontpage.
      if (drupal_is_front_page()) {
        $mission = filter_xss_admin(theme_get_setting('mission'));
      }
    
      // Construct page title
      if (drupal_get_title()) {
        $head_title = array(strip_tags(drupal_get_title()), variable_get('site_name', 'Drupal'));
      }
      else {
        $head_title = array(variable_get('site_name', 'Drupal'));
        if (variable_get('site_slogan', '')) {
          $head_title[] = variable_get('site_slogan', '');
        }
      }
      $variables['head_title']        = implode(' | ', $head_title);
      $variables['base_path']         = base_path();
      $variables['front_page']        = url();
      $variables['breadcrumb']        = theme('breadcrumb', drupal_get_breadcrumb());
      $variables['feed_icons']        = drupal_get_feeds();
      $variables['footer_message']    = filter_xss_admin(variable_get('site_footer', FALSE));
      $variables['head']              = drupal_get_html_head();
      $variables['help']              = theme('help');
      $variables['language']          = $GLOBALS['language'];
      $variables['language']->dir     = $GLOBALS['language']->direction ? 'rtl' : 'ltr';
      $variables['logo']              = theme_get_setting('logo');
      $variables['messages']          = $variables['show_messages'] ? theme('status_messages') : '';
      $variables['mission']           = isset($mission) ? $mission : '';
      $variables['primary_links']     = theme_get_setting('toggle_primary_links') ? menu_primary_links() : array();
      $variables['secondary_links']   = theme_get_setting('toggle_secondary_links') ? menu_secondary_links() : array();
      $variables['search_box']        = (theme_get_setting('toggle_search') ? drupal_get_form('search_theme_form') : '');
      $variables['site_name']         = (theme_get_setting('toggle_name') ? filter_xss_admin(variable_get('site_name', 'Drupal')) : '');
      $variables['site_slogan']       = (theme_get_setting('toggle_slogan') ? filter_xss_admin(variable_get('site_slogan', '')) : '');
      $variables['css']               = drupal_add_css();
      $variables['styles']            = drupal_get_css();
      $variables['scripts']           = drupal_get_js();
      $variables['tabs']              = theme('menu_local_tasks');
      $variables['title']             = drupal_get_title();
      // Closure should be filled last.
      $variables['closure']           = theme('closure');
    
      if ($node = menu_get_object()) {
        $variables['node'] = $node;
      }
    
      // Compile a list of classes that are going to be applied to the body element.
      // This allows advanced theming based on context (home page, node of certain type, etc.).
      $body_classes = array();
      // Add a class that tells us whether we're on the front page or not.
      $body_classes[] = $variables['is_front'] ? 'front' : 'not-front';
      // Add a class that tells us whether the page is viewed by an authenticated user or not.
      $body_classes[] = $variables['logged_in'] ? 'logged-in' : 'not-logged-in';
      // Add arg(0) to make it possible to theme the page depending on the current page
      // type (e.g. node, admin, user, etc.). To avoid illegal characters in the class,
      // we're removing everything disallowed. We are not using 'a-z' as that might leave
      // in certain international characters (e.g. German umlauts).
      $body_classes[] = preg_replace('![^abcdefghijklmnopqrstuvwxyz0-9-_]+!s', '', 'page-'. form_clean_id(drupal_strtolower(arg(0))));
      // If on an individual node page, add the node type.
      if (isset($variables['node']) && $variables['node']->type) {
        $body_classes[] = 'node-type-'. form_clean_id($variables['node']->type);
      }
      // Add information about the number of sidebars.
      if ($variables['layout'] == 'both') {
        $body_classes[] = 'two-sidebars';
      }
      elseif ($variables['layout'] == 'none') {
        $body_classes[] = 'no-sidebars';
      }
      else {
        $body_classes[] = 'one-sidebar sidebar-'. $variables['layout'];
      }
      // Implode with spaces.
      $variables['body_classes'] = implode(' ', $body_classes);
    
      // Build a list of suggested template files in order of specificity. One
      // suggestion is made for every element of the current path, though
      // numeric elements are not carried to subsequent suggestions. For example,
      // http://www.example.com/node/1/edit would result in the following
      // suggestions:
      //
      // page-node-edit.tpl.php
      // page-node-1.tpl.php
      // page-node.tpl.php
      // page.tpl.php
      $i = 0;
      $suggestion = 'mvc';
      $suggestions = array();
      while ($arg = arg($i++)) {
        $arg = str_replace(array("/", "\\", "\0"), '', $arg);
        $suggestions[] = $suggestion .'-'. $arg;
        if (!is_numeric($arg)) {
          $suggestion .= '-'. $arg;
        }
      }
      if (drupal_is_front_page()) {
        $suggestions[] = 'page-front';
      }
    
      if ($suggestions) {
        $variables['template_files'] = $suggestions;
      }
      
      return $variables;
    }
 }
?>
